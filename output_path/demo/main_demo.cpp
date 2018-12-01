
#include <BDuerSDK.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/select.h>
#include <stdio.h>

using namespace std;
using namespace bduer;

BDuerSDK* duerSDK;
void* push_audio_test(void* args);
void push_audio_stream(char* stream, unsigned int streamSize);

class ReqBack : public IBDuerSDKCallback {
public:
    ReqBack() {

    }

    ~ReqBack() {

    }

    void remote_callback(BDuerMessage& message) {
    }

    void message_callback(BDuerMessage& message) {
        if (strcmp(BDUER_CALLBACK_REGISTER_SUCCESS, message.get_name()) == 0) {
            cout << "注册成功" << endl;
            int req;
            BDuerMessage message;
            message.set_name(BDUER_CMD_START);
            message.set_parameter(BDUER_PARAM_KEY_SPEECH_ENGINE_SUPPORT, SPEECH_SUPPORT_WAKEUP_AND_ASR);
            message.set_parameter(BDUER_PARAM_KEY_AFTER_WAKE_UP, AFTER_FINISH_WAITING);
            duerSDK->post(message, &req);

            pthread_t pid;
            pthread_create(&pid, NULL, push_audio_test, NULL);

        } else if (strcmp(BDUER_CALLBACK_ASR, message.get_name()) == 0) {
            int status;
            message.get_parameter(BDUER_PARAM_KEY_ASR_STATUS, status);
            char* word;
            int len;

            switch (status) {
            case ASRStatusStart: {
                cout << "识别开始:" << endl;
                break;
            }

            case ASRStatusVadEnd: {
                break;
            }

            case ASRStatusFlushData: {
                message.get_parameter(BDUER_PARAM_KEY_ASR_DATA, word, len);
                cout << "中间识别结果:%s" << word << endl;
                break;
            }

            case ASRStatusFinish: {
                message.get_parameter(BDUER_PARAM_KEY_ASR_DATA, word, len);
                cout << "识别结果:%s" << word << endl;
                break;
            }

            case ASRStatusCancel: {
                cout << "识别取消" << endl;

                break;
            }

            case ASRStatusMeterLevel: {
                int volume;
                message.get_parameter(BDUER_PARAM_KEY_ASR_METER_LEVEL, volume);
                //cout << "音量为:%d" << volume << endl;
                break;
            }

            default:
                ;
            }
        } else if (strcmp(BDUER_CALLBACK_TTS, message.get_name()) == 0) {
            int status;
            message.get_parameter(BDUER_PARAM_KEY_TTS_STATUS, status);

            switch (status) {
            case TTSStatusBegin: {
                cout << "语音合成开始:" << endl;
                break;
            }

            case TTSStatusAudioData: {
                /**
                * char *stream　是返回的tts数据
                * int length    是返回的tts的数据长度
                */
                char* stream;
                int length;
                message.get_parameter(BDUER_PARAM_KEY_TTS_AUDIO_DATA, stream, length);
                break;
            }

            case TTSStatusFinish: {
                cout << "语音合成结束..." << endl;
                break;
            }

            default:
                ;
            }
        } else if (strcmp(BDUER_CALLBACK_DUER, message.get_name()) == 0) {
            char* content;
            int len;
            message.get_parameter(BDUER_PARAM_KEY_DUER_SERVER_CONTENT, content, len);
        } else if (strcmp(BDUER_CALLBACK_HTTP_RESPONSE, message.get_name()) == 0) {
            char* content;
            int length = 0;
            message.get_parameter(BDUER_PARAM_KEY_HTTP_RESPONSE, content, length);
            //@
            Json::Reader reader;
            Json::Value data_json;
            bool ret = reader.parse(content, data_json);
            if (ret) {
                const Json::Value &result = data_json["result"];
                if (result.isMember("directives")) {
                    const Json::Value &directives = result["directives"];
                    if (directives.isArray()) {
                        for (int i = 0; i < directives.size(); ++i) {
                            const Json::Value &one_directive = directives[i];
                            if (one_directive.isMember("header")) {
                                const Json::Value &header = one_directive["header"];
                                string nameSpace = header["namespace"].asString();
                                string name = header["name"].asString();
                                if (nameSpace == "SpeechSynthesizer" && name == "Speak") {
                                    const Json::Value &payload = one_directive["payload"];
                                    const Json::Value &content = payload["content"];
                                    if (content.isArray()) {
                                        string voice = content[0].asString();
                                        std::cout << "network result voice :" << voice << endl;
                                        if (voice.length() > 0) {
                                            const char *ttsVoice = voice.c_str();
                                            int length = strlen(ttsVoice);
                                            BDuerMessage msg;
                                            msg.set_name((char *) BDUER_CMD_TTS_STR);
                                            msg.set_parameter((char *) BDUER_PARAM_KEY_TTS_STR,
                                                              ttsVoice, length);
                                            int req = 0;
                                            duerSDK->post(msg, &req);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
         } else if (strcmp(BDUER_CALLBACK_WAKEUP, message.get_name()) == 0) {
            int status;
            message.get_parameter(BDUER_PARAM_KEY_WAKEUP_STATUS, status);

            switch (status) {
            case WakeupStatusTriggered: {
                int req;
                printf("唤醒成功");
                //进入识别模式
                BDuerMessage message;
                message.set_name((char*) BDUER_CMD_OPEN_SPEECH_ENGINE);
                message.set_parameter(BDUER_PARAM_KEY_OPEN_SPEECH_ENGINE, SPEECH_ENGINE_ASR);
                duerSDK->post(message, &req);

                break;
            }

            default:
                break;
            }
        } else if (strcmp(BDUER_CALLBACK_FINAL, message.get_name()) == 0) {
            char* errorMsg;
            int len;
            int errorCode;
            message.get_parameter(BDUER_PARAM_KEY_ERROR_CODE, errorCode);
            message.get_parameter(BDUER_PARAM_KEY_ERROR_DESC, errorMsg, len);

            switch (errorCode) {
            case BDuerTTSErrorCode :
                cout << "ERROR CODE: BDuerTTSErrorCode, Error MSG:%s" << errorMsg << endl;
                break;

            case BDuerSDKFinishCode:
                cout << " BDuerSDKFinishCode " << endl;
                break;

            case BDuerRegisterErrorCode:
                cout << "ERROR CODE: BDuerRegisterErrorCode, Error MSG:%s" << errorMsg << endl;
                break;

            case BDuerWakeupErrorCode:
                cout << "ERROR CODE: BDuerWakeupErrorCode, Error MSG:%s" << errorMsg << endl;
                break;

            case BDuerASRErrorCode:
                cout << "ERROR CODE: BDuerASRErrorCode, Error MSG:%s" << errorMsg << endl;
                break;

            case BDuerSDKErrorCode:
                cout << "ERROR CODE: BDuerSDKErrorCode, Error MSG:%s" << errorMsg << endl;
                break;

            case BDuerDUMIServerErrorCode:
                cout << "ERROR CODE: BDuerDUMIServerErrorCode, Error MSG:%s" << errorMsg << endl;
                break;
            }
        }
    };
};

void* push_audio_test(void* args) {
    char audioBuf[4000] = {0};
    FILE* fp = fopen("./record.pcm", "rb");

    if (fp != NULL) {

        while (!feof(fp)) {
            size_t readCount = fread(audioBuf, 1, 4000, fp);

            //cout << "DataRead: " << readCount << endl;
            if (readCount > 0) {

                push_audio_stream(audioBuf, (int)readCount);

                usleep(125000); // 4000 bytes is 0.125 seconds of audio, sleep 0.125 seconds to simulate actual conditions if recording
            }
        }

        push_audio_stream(audioBuf, 0);

        fclose(fp);
        sleep(5);
    } else {
        cout << "Failed open audio file" << endl;
    }
}

//用于推送录音数据
void push_audio_stream(char* stream, unsigned int streamSize) {

    int req;
    BDuerMessage message;
    message.set_name((char*) BDUER_CMD_AUDIORECORDER_PCM_STREAM_BUFFER);
    message.set_parameter(BDUER_PARAM_KEY_AUDIORECORDER_PCM_STREAM_DATA, (const char*) stream,
                          streamSize);
    duerSDK->post(message, &req);
}

int main(int argc, char** argv) {

    duerSDK = BDuerSDK::get_instance();

    ReqBack* reqBack = new ReqBack();
    duerSDK->set_event_lisner(reqBack);
    const string id = "123";
    duerSDK->init("dm860970181FC44B79", "9A22001A8CCE49AFA9B11D6FBA26CFA1", "test", "");

    while (1) {
        struct timeval wait = {0, 100 * 1000};
        ::select(0, NULL, NULL, NULL, &wait);
    }
}

