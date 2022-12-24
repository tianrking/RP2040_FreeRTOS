#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

SemaphoreHandle_t count;

void vBlinkTask() {
   for (;;) {
      // tick
      // xSemaphore：信号量句柄
      // xBlockTime：等待信号量可用的最大超时时间，单位为 tick（即系统节拍周期）。如果宏 INCLUDE_vTaskSuspend 定义为 1 且形参 xTicksToWait 设置为 portMAX_DELAY ，则任务将一直阻塞在该信号量上（即没有超时时间）

      if(xSemaphoreTake(count,(TickType_t) 10) == pdTRUE){
         gpio_put(PICO_DEFAULT_LED_PIN, 1);
         vTaskDelay(100);
      }
      else{
         gpio_put(PICO_DEFAULT_LED_PIN, 0);
         vTaskDelay(1);
      }
   }
}

void button_task(){

   while(true){
      if(gpio_get(20)!=0){
         xSemaphoreGive(count);
         vTaskDelay(20);
      }
      else{
         vTaskDelay(20);
      }
   }
}

int main() {

   stdio_init_all();

   gpio_init(PICO_DEFAULT_LED_PIN);
   gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
   gpio_init(20);
   gpio_set_dir(20,GPIO_IN);

   count = xSemaphoreCreateCounting(10,0);

   xTaskCreate(vBlinkTask, "Blink Task", 128, NULL, 1, NULL);
   xTaskCreate(button_task, "button_task", 128, NULL, 1, NULL);

   vTaskStartScheduler();

}