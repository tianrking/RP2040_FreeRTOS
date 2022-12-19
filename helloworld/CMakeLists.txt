cmake_minimum_required(VERSION 3.21)

include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(picoexp C CXX ASM)

set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(helloworld main.c)
target_link_libraries(helloworld pico_stdlib)

pico_enable_stdio_usb(helloworld 1)
pico_enable_stdio_uart(helloworld 0)

pico_add_extra_outputs(helloworld)
