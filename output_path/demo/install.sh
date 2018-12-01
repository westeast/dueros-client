#!/bin/sh
rm -rf /duer
mkdir /duer
mkdir /duer/lib
cp -rf demo record.pcm ../resources/ ../sdkconfigs/ /duer
cp ../libduersdk.so /duer/lib
cp -d ../deps_libs/* /duer/lib

echo "安装完成"
