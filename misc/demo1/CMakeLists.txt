cmake_minimum_required(VERSION 3.21)

include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(app C CXX ASM)

set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(demo1 main.c)
target_link_libraries(demo1 pico_stdlib)
target_link_libraries(demo1 pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)
target_include_directories(demo1 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_enable_stdio_usb(demo1 1)
pico_enable_stdio_uart(demo1 0)

pico_add_extra_outputs(demo1)
