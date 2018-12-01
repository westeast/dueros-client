//
// Created by jianchuanli on 17-3-7.
//

#ifndef DUER_LINUX_DEVICE_H
#define DUER_LINUX_DEVICE_H

#include "BDuerConstant.h"
#include <pthread.h>
#include <string>

namespace bduer {
    class Device {
    public:
        Device(const char *name);

        Device();
        virtual ~Device();

        virtual void insert_status(const struct DeviceStatus& device_status) = 0;

        virtual void get_status(std::string &status) = 0;

        virtual void parse_event(const struct DeviceEvent& device_event,std::string &event) = 0;

        virtual std::string get_name();

    protected:
        pthread_mutex_t mutex;
    private:
        std::string name;
    };
}
#endif //DUER_LINUX_DEVICE_H
