cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Pull in FreeRTOS
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)


project(app C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK 
pico_sdk_init()

add_subdirectory(helloworld)
add_subdirectory(Blinky_Task)
add_subdirectory(Tasks_and_Queues)
add_subdirectory(Scheduling_Task_Priorities)
add_subdirectory(Mutex)
add_subdirectory(Semaphores)
add_subdirectory(misc)
add_subdirectory(MicroROS)
