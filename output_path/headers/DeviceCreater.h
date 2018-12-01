//
// Created by jianchuanli on 17-3-16.
//

#ifndef DUER_LINUX_DEVICEINTERFACE_H
#define DUER_LINUX_DEVICEINTERFACE_H

#include "Device.h"
namespace bduer {
    class DeviceCreater {
    public:
        virtual Device* createCustomDevice(DeviceName name) = 0;
    };
}
#endif //DUER_LINUX_DEVICEINTERFACE_H
