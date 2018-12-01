cmake_minimum_required(VERSION 3.6)
project(demo)

# 清替换成您的交叉编译工具
set(CMAKE_C_COMPILER "/opt/Tonlyele_Speaker/toolchain/bin/arm-openwrt-linux-gcc")
set(CMAKE_CXX_COMPILER "/opt/Tonlyele_Speaker/toolchain/bin/arm-openwrt-linux-gcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 生成的可执行文件存放路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# 设置rpath
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath,'/duer/lib'")

# 头文件路径
include_directories(../headers)

# 库文件路径
link_directories("../deps_libs")
link_directories("..")

# 源文件
set(DEMO_SOURCE_FILES
        main_demo.cpp
        )

# 生成可执行文件
add_executable(demo ${DEMO_SOURCE_FILES})

# 依赖的第三方库
target_link_libraries(demo duersdk  curl ssl crypto z iconv charset dl pthread jsoncpp)

