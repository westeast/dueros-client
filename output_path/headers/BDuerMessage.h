/****************************************************************
 * 
 * Copyright (c) 2016 Baidu.com,Inc.All Rights Reserved
 *
 ****************************************************************/

/**
 * @file  BDuerMessage.h
 * @author zhaolifeng@baidu.com
 * date   2016年 11月 14日 星期一 19:30:10 CST
 * Description: BDuserMessage class
 **/
#ifndef __BDUER_MESSAGE_H_
#define __BDUER_MESSAGE_H_

class BDuerInternalMessage;
namespace bduer {
    class BDuerMessage {
    public:
        void set_parameter(const char* key, int value);
        void set_parameter(const char* key, const char *value, int valueLen);

        bool get_parameter(const char* key, int &outValue);
        bool get_parameter(const char* key, char *&outValue, int &outValueLen);

        //char* name;
        void set_name(const char *name);
        const char *get_name()const;

        BDuerMessage(const BDuerMessage &msg);
        BDuerMessage();
        ~BDuerMessage();
        BDuerMessage& operator=(const BDuerMessage &msg);
    private:
        BDuerInternalMessage *m_pInternal_message;

    };
}

#endif

