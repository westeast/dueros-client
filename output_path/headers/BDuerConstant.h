#ifndef _BDUER_CONSTANT_H_
#define _BDUER_CONSTANT_H_

#include <vector>
#include <string>
#include "json/json.h"

namespace bduer {
    /**
     * post(&message)消息命令名称(message.mName)
     **/
    //sdk开始工作的接口
    extern const char *BDUER_CMD_START;
    //sdk停止工作接口
    extern const char *BDUER_CMD_STOP;
    //设置sdk唤醒后的状态
    extern const char *BDUER_CMD_CHANGE_AFTER_WAKE_UP;
    //设置当前sdk打开的语音引擎类型（语音唤醒/语音识别）
    extern const char *BDUER_CMD_OPEN_SPEECH_ENGINE;
    //设置用户BDUSS（登录态参数）
    extern const char *BDUER_CMD_SET_USER_BDUSS;
    //清除用户BDUSS（登录态参数）
    extern const char *BDUER_CMD_CLEAR_USER_BDUSS;
    //关闭取消当前语音引擎
    extern const char *BDUER_CMD_CANCEL_SPEECH_ENGINE;
    //打开当前语音引擎
    extern const char *BDUER_CMD_START_SPEECH_ENGINE;
    //查询当前工作状态
    extern const char *BDUER_CMD_CHECK_CUR_WORK_STATE;
    //发送请求
    extern const char *BDUER_CMD_SEND_HTTP_REQUEST;
    //切换TTS引擎（男生，女生等）
    extern const char *BDUER_CMD_SWITCH_TTS_ENGINE_TYPE;
    //@
    extern const char *BDUER_CMD_SET_WRITE_FILE_CONFIG;
    //@cxt 20170524
    extern  const char *BDUER_CMD_STAT_MUSIC_PLAY_TIME;
    //@
    extern const char *BDUER_CMD_DEVICE_MATCH;
    //@cxt
    extern const char *BDUER_CMD_CLEANUP;
    //@cxt 20170605
    extern const char *BDUER_CMD_SET_DUER_REQUEST_QUERY;

    extern const char *BDUER_CMD_GET_TTS_ENGINE_TYPE;

    extern const char *BDUER_CMD_DO_HTTP_REQUEST;

    /**
    * post(&message)方法调用返回
    **/
    extern const int BDUER_POST_SUCCESS;

    /**
    * params_key
    * post(&message)消息
    * 调用参数key值
    * **/

    /**状态参数**/
    //tts
    extern const char *BDUER_PARAM_KEY_TTS_STATE;
    //语音识别
    extern const char *BDUER_PARAM_KEY_VOICE_STATE;
    //语音唤醒
    extern const char *BDUER_PARAM_KEY_WAKEUP_STATE;
    //支持引擎
    extern const char *BDUER_PARAM_KEY_SPEECH_ENGINE_SUPPORT;
    //引擎资源文件的目录父路径
    extern const char *BDUER_PARAM_KEY_SPEECH_RES_FILE_PATH;
    //SDK配置路径设置
    extern const char *BDUER_PARAM_KEY_SDK_CONFIG_FILE_PATH;
    // local write file path
    extern const char *BDUER_PARAM_KEY_LOCAL_WRITE_FILE_PATH;
    // local write file name
    extern const char *BDUER_PARAM_KEY_LOCAL_WRITE_FILE_NAME;
    //引擎当前工作状态
    extern const char *BDUER_PARAM_KEY_SPEECH_ENGINE_STATE;
    //唤醒后的工作状态
    extern const char *BDUER_PARAM_KEY_AFTER_WAKE_UP;
    //@ cxt 20170504
    extern const char *BDUER_PARAM_KEY_SUPPORTED_CONTENT_TYPE;
    //@ cxt 20170525
    extern const char *BDUER_PARAM_KEY_MUSIC_PLAY_TIME;
    extern const char *BDUER_PARAM_KEY_MUSIC_LOG_ID;
    //@ cxt 20170605
    extern const char *BDUER_PARAM_KEY_QUERY_WORDS;

    /**状态参数**/

    //开启引擎参数
    extern const char *BDUER_PARAM_KEY_OPEN_SPEECH_ENGINE;
    //用户BDUSS参数
    extern const char *BDUER_PARAM_KEY_USER_BDUSS;
    //度秘服务器返回结果参数
    extern const char *BDUER_PARAM_KEY_DUER_SERVER_CONTENT;
    //发送请求类型
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_TYPE;
    //client_msg_id
    extern const char *BDUER_PARAM_KEY_CLIENT_MSG_ID;
    //发送请求body
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_BODY;
    //请求返回内容
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE;

    extern const char *BDUER_PARAM_KEY_REGISTER;
    extern const char *BDUER_PARAM_KEY_REGISTER_MSG;

    //@cxt 20170814
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_HEADERS;
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_METHOD;
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_DATA_TYPE;
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_TOKEN;
    extern const char *BDUER_PARAM_KEY_HTTP_REQUEST_URL;

    /**
    * params_value
    * post(&message)消息
    * 调用参数value值
    * **/
    extern const char *BDUER_PARAM_KEY_REGISTER_OK;

    //@tts_engine_type
    extern const char *BDUER_PARAM_KEY_SWITCH_TTS_ENGINE_TYPE;
    //登录的状态
    extern const char *BDUER_PARAM_KEY_USER_LOGIN_STATUS;
    //登录的状态
    extern const char *BDUER_PARAM_KEY_USER_LOGIN_ERROR_INFO;

    extern const char *BDUER_PARAM_KEY_USER_LOGOUT_STATUS;

    /*
    * device info name & key
    */
    // message.name
    extern const char *BDUER_DEVICE_INFO;
    // message.key
    extern const char *BDUER_DEVICE_ID; // device_id
    extern const char *BDUER_DEVICE_NAME; // device_name
    extern const char *BDUER_DEVICE_VERSION; // device_version
    extern const char *BDUER_DEVICE_SOFTWARE_VERSION; // software_version
    extern const char *BDUER_DEVICE_SYS_VERSION; // sys_version
    extern const char *BDUER_DEVICE_MAC_ADDRESS; // mac
    extern const char *BDUER_DEVICE_SN;// sn
    extern const char *BDUER_DEVICE_CUID;//cuid
    extern const char *BDUER_DEVICE_IP; //ip
    extern const char *BDUER_DEVICE_OWNER_USER_ID; // owner_userid
    extern const char *BDUER_DEVICE_USER_ID; // userid
    extern const char *BDUER_DEVICE_VOLUME;// volume
    extern const char *BDUER_DEVICE_MUTE; // mute
    extern const char *BDUER_DEVICE_CHARGING; //mute
    extern const char *BDUER_DEVICE_CHARGE_LEVEL; // charge_level
    extern const char *BDUER_DEVICE_SSID;

    /**
    * post(&message)消息回调的callback命令名称(message.mName)
    **/
    //注册成功的回调
    extern const char *BDUER_CALLBACK_REGISTER_SUCCESS;
    //sdk开始工作的回调（暂未使用）
    extern const char *BDUER_CALLBACK_START;
    //sdk停止工作的回调（暂未使用）
    extern const char *BDUER_CALLBACK_STOP;
    //sdk语音唤醒回调
    extern const char *BDUER_CALLBACK_WAKEUP;
    //sdk语音识别的回调
    extern const char *BDUER_CALLBACK_ASR;
    //sdk度秘服务端语义解析返回的结果回调
    extern const char *BDUER_CALLBACK_DUER;
    //sdk中tts合成的回调
    extern const char *BDUER_CALLBACK_TTS;
    //sdk一次运行结束的回调
    extern const char *BDUER_CALLBACK_FINAL;
    //向sdk中调用发送HTTP接口的回调
    extern const char *BDUER_CALLBACK_HTTP_RESPONSE;

    extern const char *BDUER_CALLBACK_USER_LOGIN;

    extern const char *BDUER_CALLBACK_USER_LOGOUT;

    extern const char *BDUER_CALLBACK_GET_TTS_ENGINE_TYPE;

    extern const char *BDUER_CALLBACK_HTTP_REQUEST;
//@cxt 20170814
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE_HEADERS;
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE_BODY;
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE_TOKEN;
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE_SUCCESS;
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE_CODE;
    extern const char *BDUER_PARAM_KEY_HTTP_RESPONSE_ERR_MSG;

    /**
     * mateApp远程(&message)消息回调的callback命令名称(message.mName)
    **/
    /**
     * post(message) message name
     */
    extern const char *BDUER_CMD_TTS_STR;
    extern const char *BDUER_PARAM_KEY_TTS_STR;
    //@cxt 20170502
    extern const char *BDUER_PARAM_KEY_TTS_STOP;
    //@
    extern const char *BDUER_PARAM_KEY_TTS_LOG_ID;
    extern const char *BDUER_CMD_AUDIORECORDER_PCM_STREAM_BUFFER;
    extern const char *BDUER_PARAM_KEY_AUDIORECORDER_PCM_STREAM_DATA;


    /**
    * params_key
    * post(&message)消息回调的callback
    * 调用参数key值
    * **/
    extern const char *BDUER_PARAM_KEY_ERROR_CODE;
    extern const char *BDUER_PARAM_KEY_ERROR_DESC;
    extern const char *BDUER_PARAM_KEY_SUB_ERROR_CODE;

    //语音识别
    extern const char *BDUER_PARAM_KEY_ASR_ERROR_CODE;
    extern const char *BDUER_PARAM_KEY_ASR_STATUS;
    extern const char *BDUER_PARAM_KEY_ASR_DATA;
    extern const char *BDUER_PARAM_KEY_ASR_METER_LEVEL;

    //tts
    extern const char *BDUER_PARAM_KEY_TTS_ENGINE_TYPE;

    //语音识别枚举状态
    typedef enum ASRStatus {
        ASRStatusInit = 0,
        ASRStatusStart,         // 检测到用户开始说话
        ASRStatusVadEnd,
        ASRStatusFlushData,              // 连续上屏
        ASRStatusFinish,                 // 语音识别功能完成，服务器返回正确结果
        ASRStatusMeterLevel,             // 当前音量回调
        ASRStatusCancel                 // 用户取消
        //ASRStatusError,                  // 发生错误
    } ASRStatus;

    //语音唤醒
    extern const char *BDUER_PARAM_KEY_WAKEUP_STATUS;
    //语音唤醒枚举状态
    typedef enum WakeupStatus {
        WakeupStatusTriggered,   // 命中唤醒词
        //WakeupStatusError,       // 引擎发生错误
    } WakeupStatus;

    //TTS合成
    extern const char *BDUER_PARAM_KEY_TTS_STATUS;
    extern const char *BDUER_PARAM_KEY_TTS_AUDIO_DATA;
    extern const char *BDUER_PARAM_KEY_TTS_STRING_INDEX;
    extern const char *BDUER_PARAM_KEY_TTS_SYNTHESIZE_CHAR_INDEX;

    //语音唤醒枚举状态
    typedef enum TTSStatus {
        TTSStatusBegin,   // 语音合成开始
        TTSStatusAudioData, // 正在合成语音
        TTSStatusFinish, // 语音合成结束
    } TTSStatus;

    /**
    * pragma mark - 度秘错误状态
    */
    typedef enum BDuerErrorCode {
        BDuerTTSErrorCode = 10001,//TTS
        BDuerRegisterErrorCode,
        BDuerWakeupErrorCode,//唤醒
        BDuerASRErrorCode,//语音识别
        BDuerSDKErrorCode,
        BDuerDUMIServerErrorCode,//度秘后台
        BDuerSDKFinishCode,
    } BDuerErrorCode;

    typedef enum LoginStatus {
        LOGIN_SUCCESS,
        LOGIN_FAILED,
    }LoginStatus;

    typedef enum LogoutStatus {
        LOGOUT_SUCCESS,
        LOGOUT_FAILED,
    }LogoutStatus;


    typedef enum BDuerAsrSubCode {
        AsrErrorCodeNoSpeech
    } BDuerAsrSubCode;

    typedef enum MessageId {
        MSG_ID_INIT = 0000,
        MSG_ID_REGISTER = 1000,
        MSG_ID_WAKE_UP = 2000,
        MSG_ID_ASR_STATUS = 3000,
        MSG_ID_ASR = 4000,
        MSG_ID_DUER_SERVICE = 5000,
        MSG_ID_TEXT_SYNTHESIZE = 6000,
        MSG_ID_TEXT_SYNTHESIZE_START = 7000,
        MSG_ID_TEXT_SYNTHESIZE_DATA = 8000,
        MSG_ID_TEXT_SYNTHESIZE_FINISH = 9000,
        MSG_ID_SESSION_FINISH = 10000,
        MSG_ID_IPC_SOCKET_TIME = 11000
    } MessageId;

    typedef enum TTSType {
        TTS_Unknown = -1,
        TTS_Reminder = 0, //
        TTS_Broadcast
    } TTSType;

    //开始设置语音引擎的类型
    typedef enum SpeechEngineSupport {
        //只支持语音识别
                SPEECH_SUPPORT_ASR,
        //仅支持语音唤醒
                SPEECH_SUPPORT_WAKEUP,
        //支持语音唤醒和识别
                SPEECH_SUPPORT_WAKEUP_AND_ASR,
    } SpeechEngineSupport;

    //当前工作的引擎
    typedef enum SpeechEngineState {
        //语音引擎
                SPEECH_ENGINE_ASR,
        //等待引擎（不接受任何录音数据）
                SPEECH_ENGINE_WAITING,
        //唤醒引擎
                SPEECH_ENGINE_WAKEUP,
    } SpeechEngineState;

    //唤醒后的工作状态（需要在设置了支持SPEECH_SUPPORT_WAKEUP_AND_ASR之后才有效）
    typedef enum AfterFinishWakeUp {
        //唤醒后进入等待引擎（需要外部启动开启后续工作）
                AFTER_FINISH_WAITING,
        //唤醒后直接进入语音识别引擎
                AFTER_FINISH_OPEN_ASR_ENGINE
    } AfterFinishWakeUp;

    typedef enum _ttsEngineType {
        ttsEngineType_Female = 0,
        ttsEngineType_male_normal = 1,
        ttsEngineType_male_special = 2,
        ttsEngineType_male_emotion = 3,
        ttsEngineType_children_emotion = 4
    } ttsEngineType;

    typedef enum HttpRequestType {
        //事件上报请求
                HTTP_REQUEST_TYPE_EVENT,
        //闹钟拉取请求
                HTTP_REQUEST_TYPE_ALARM,
                HTTP_REQUEST_TYPE_DIRECTIVE

    } HttpRequestType;

    typedef enum DeviceName {  //支持的device类型
        NAME_AUDIOPLAYER,
        NAME_SPEAKER,
        NAME_SPEECHSYNTHESIZER,
        //@cxt 20170411
        NAME_ALERTS,
        NAME_HTTP
    }DeviceName;

    typedef enum DeviceEventType {  //Device事件类型
        AUDIOPLAYER_PLAYBACK_STARTED,
        AUDIOPLAYER_PLAYBACK_STOPPED,
        AUDIOPLAYER_PLAYBACK_FINISHED,
        AUDIOPLAYER_PROGRESS_REPORT_INTERVAL_ELAPSED,
        AUDIOPLAYER_PLAYBACK_NEARLY_FINISHED,
        SPEAKER_VOLUME_CHANGED,
        SPEAKER_MUTE_CHANGED,
        SPEECHSYNTHESIZER_SPEECH_STARTED,
        SPEECHSYNTHESIZER_SPEECH_FINISHED,
        SPEECHSYNTHESIZER_SPEECH_STOPPED,
        // Alerts
        ALERTS_SET_ALERT_SUCCEEDED,
        ALERTS_SET_ALERT_FAILED,
        ALERTS_DELETE_ALERT_SUCCEEDED,
        ALERTS_DELETE_ALERT_FAILED,
        ALERTS_ALERT_STARTED,
        ALERTS_ALERT_STOPED,
        // Http
        HTTP_REQUEST_SUCCEEDED,
        HTTP_REQUEST_FAILED
    }DeviceEventType;

    typedef enum AudioPlayerState { //播放器状态
        AUDIOPLAYER_IDEL, //初始化
        AUDIOPLAYER_PLAYING, //正咋播放
        AUDIOPLAYER_PAUSED, //播放暂停
        AUDIOPLAYER_FINISHED, //播放完成
        AUDIOPLAYER_STOPPED // 停止
    }AudioPlayerState;

    struct AudioPlayerPayload {  //播放器device的事件上传内容
        const char* token;
        long offset_ms;
        AudioPlayerPayload() {
            token = "";
            offset_ms = -1;
        }
    };

    struct AudioPlayer { //播放器device
        long offset_ms;
        const char* token;
        int token_len;
        AudioPlayerState player_activity;
        AudioPlayer() {
            token = "";
            token_len = 0;
            offset_ms = -1;
            player_activity = AUDIOPLAYER_IDEL;
        }
    };

    struct SpeakerPayload {   //扬声器device的事件上传内容
        int volume;
        bool muted;
    };

    struct Speaker { //扬声器device
        int volume;
        bool muted;
        Speaker() {
            volume = 0;
            muted = false;
        }
    };

    typedef enum SpeechSynthesizerState { //TTS合成deivce状态
        SPEECHSYNTHESIZER_IDEL,
        SPEECHSYNTHESIZER_PLAYING,
        SPEECHSYNTHESIZER_FINISHED
    }SpeechSynthesizerState;

    struct SpeechSynthesizerPayload { //TTS合成device的事件上传内容
        const char* token;
        SpeechSynthesizerPayload() {
            token = "";
        }
    };

    struct SpeechSynthesizer { //TTS合成device
        const char* token;
        long offset_ms;
        int token_len;
        SpeechSynthesizerState player_activity;
        SpeechSynthesizer() {
            token = "";
            token_len = 0;
            offset_ms = -1;
            player_activity = SPEECHSYNTHESIZER_IDEL;
        }
    };

    //@cxt 20170411
    struct AlertsPayload {
        const char* token;
        AlertsPayload(){
            token = "";
        }
    };

    //@ 20170815
    struct HttpRequestSucceededPayload {
        std::string token;
        std::string code;
        Json::Value headers;
        Json::Value body;
    };

    struct HttpRequestFailedPayload {
        std::string token;
        std::string reason;
        std::string error_message;
    };

    //@cxt 20170411
    struct Alerts_Device_Status {
        //std::vector<std::string> allAlerts;
        //std::vector<std::string> activeAlerts;
        std::string alerts_status;
    };

    struct EventHeader {  //上传事件头协议
        DeviceName name_space;
        DeviceEventType name;
        const char* message_id;
        EventHeader() {
            message_id = "";
        }
    };

    struct DeviceEvent {  //Device上传的事件
        struct EventHeader header;
        struct AudioPlayerPayload audioPlayerPayload;
        struct SpeechSynthesizerPayload speechSynthesizerPayload;
        struct SpeakerPayload speakerPayload;
        //@cxt 20170411
        struct AlertsPayload alertsPayload;
        //@ 20170815
        HttpRequestSucceededPayload requestSuccPayload;
        HttpRequestFailedPayload requestFailedPayload;
    };

    struct DeviceStatus {  //Device的状态
        struct AudioPlayer audioPlayer;
        struct Speaker speaker;
        struct SpeechSynthesizer speechSynthesizer;
        //@cxt 20170411
        struct Alerts_Device_Status alerts_device_status;
    };
};
#endif
