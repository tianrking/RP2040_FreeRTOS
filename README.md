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

## SMP-demo 

https://github.com/FreeRTOS/FreeRTOS-SMP-Demos
