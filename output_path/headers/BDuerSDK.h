/****************************************************************
 * 
 * Copyright (c) 2016 Baidu.com,Inc.All Rights Reserved
 *
 ****************************************************************/

/**
 * @file  BDuerSDK.h
 * @author zhaolifeng@baidu.com
 * date   2016年 11月 14日 星期一 19:30:10 CST
 * Description: BDuserSDK class
 **/

#ifndef __BDUER_SDK_H_
#define __BDUER_SDK_H_

#include "BDuerConstant.h"
#include "BDuerMessage.h"
#include "IBDuerSDKCallback.h"
#include "pthread.h"
using namespace bduer;

namespace bduer {

    class BDuerSDK {
    public:

        static BDuerSDK *get_instance();

        /**
        * 初始化SDK
        * @param appId 申请的appid
        * @param appKey  申请的appkey
        * @param deviceId  使用设备的id
        * @param bduss 用户登录信息
        * return req   返回值，调用成功返回BDUER_POST_SUCCESS
        */
        int init(const char *appId, const char *appKey, const char *deviceId, const char *passcode = NULL);

        /**
         * 设置sdk监听回调
         * @param callback
         */
        void set_event_lisner(IBDuerSDKCallback *callback);

        /**
         * 向sdk发送消息指令
         * @param message 具体消息内容
         * @param req 返回值，调用成功返回BDUER_POST_SUCCESS
         */
        void post(BDuerMessage &message, int *req);

        /**
         * 销毁sdk
         */
        void release();

    private:
        BDuerSDK();

        ~BDuerSDK();

        static void internal_init();
        static void internal_destroy();
        static BDuerSDK *mBDuerSDK;
        static pthread_once_t m_init_once;
        static pthread_once_t m_destroy_once;
    };
}
#endif
