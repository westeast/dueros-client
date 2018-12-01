//
// Created by jianchuanli on 17-3-7.
//

#ifndef DUER_LINUX_DEVICEPROVIDER_H
#define DUER_LINUX_DEVICEPROVIDER_H

#include <pthread.h>
#include "DeviceCreater.h"

class DeviceInternalProvider;

namespace bduer {
    class DeviceProvider {
    private:
        static DeviceProvider *m_instance;
        static pthread_once_t m_init_once;
        static pthread_once_t m_destroy_once;
        pthread_mutex_t m_mutex;

        DeviceProvider();

        ~DeviceProvider();

        static void init();

        static void internal_destroy();

        DeviceInternalProvider *internal_provider;

        DeviceCreater *creater;
    public:
        static DeviceProvider *get_instance();

        bool add_device(DeviceName device);

        void remove_device(DeviceName device);

        void remove_all();

        void destroy();

        void add_device_status(DeviceName device, const struct DeviceStatus& device_status);

        //void get_device_event(DeviceName name, struct DeviceEvent device_event, char *&event, int &len);
        void get_device_event(DeviceName name,const struct DeviceEvent& device_event,std::string &event);

        //void get_device_status(char *&result);
        void get_device_status(std::string &result);

        //void get_device_interface(char *&result);
        void get_device_interface(std::string &result);

        void set_device_creater(DeviceCreater *creater);
    };
}


#endif //DUER_LINUX_DEVICEPROVIDER_H
