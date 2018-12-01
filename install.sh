#!/bin/sh
systemctl stop duer
rm -rf /duer
mkdir /duer
mkdir /duer/lib
tar zxvf sdk_output.tar.gz
cp -r duer_daemon duer_linux duer_audio_player duer_timer duer_link version.txt appresources output_path/sdkconfigs output_path/resources output_path/docs /duer
cp -d output_path/libduersdk.so deps_libs/* output_path/deps_libs/* /duer/lib
#echo "/duer/lib" > /etc/ld.so.conf.d/duer.conf
#ldconfig
sync
echo "安装完成"
