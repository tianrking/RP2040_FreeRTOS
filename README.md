# RP2040_FreeRTOS

```bash
git clone https://github.com/RaspberryPi/pico-sdk --recurse-submodules
git clone -b smp https://github.com/FreeRTOS/FreeRTOS-Kernel --recurse-submodules ## git submodule update --init --recursive
export PICO_SDK_PATH=$PWD/pico-sdk
export FREERTOS_KERNEL_PATH=$PWD/FreeRTOS-Kernel
git clone https://github.com/tianrking/RP2040_FreeRTOS
```

```bash
mkdir build
cd build
cmake ..
make
```

## Integration MicroROS

```bash
git clone https://github.com/micro-ROS/micro_ros_raspberrypi_pico_sdk ~/micro_ROS_SDK_PATH
export micro_ROS_SDK_PATH=~/micro_ROS_SDK_PATH
```

## SMP-demo 

https://github.com/FreeRTOS/FreeRTOS-SMP-Demos
