#ifndef __BDUER_SDK_CALLBACK_
#define __BDUER_SDK_CALLBACK_
namespace bduer{
	class IBDuerSDKCallback{
	public:
		virtual void message_callback(BDuerMessage &message) = 0;
        virtual void remote_callback(BDuerMessage &message) = 0;
		virtual void account_callback(BDuerMessage &message) {
			//TODO 帐号登录回调
		};

	};
}
#endif
