cmake_minimum_required(VERSION 3.21)

include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(app C CXX ASM)

set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(Mutex_Chaos chaos.c)
target_link_libraries(Mutex_Chaos pico_stdlib)
target_link_libraries(Mutex_Chaos pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)
target_include_directories(Mutex_Chaos PRIVATE ${CMAKE_CURRENT_LIST_DIR})
pico_enable_stdio_usb(Mutex_Chaos 1)
pico_enable_stdio_uart(Mutex_Chaos 0)
pico_add_extra_outputs(Mutex_Chaos)


add_executable(Mutex main.c)
target_link_libraries(Mutex pico_stdlib)
target_link_libraries(Mutex pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)
target_include_directories(Mutex PRIVATE ${CMAKE_CURRENT_LIST_DIR})
pico_enable_stdio_usb(Mutex 1)
pico_enable_stdio_uart(Mutex 0)
pico_add_extra_outputs(Mutex)

