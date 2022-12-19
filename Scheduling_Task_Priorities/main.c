#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

void task1(void *pvParameters){
   while(true){
      printf("Task11111111111111\n");
      for(int i=0;i<20000000;i++){
         ;
      }
   }
}


void task2(void *pvParameters){
   while(true){
      printf("Task222222222222222\n");
      for(int i=0;i<20000000;i++){
         ;
      }
   }
}

int main() {

   stdio_init_all();

   // gpio_init(PICO_DEFAULT_LED_PIN);
   // gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

   xTaskCreate(task1, "Task 1", 128, NULL, 1, NULL);
   xTaskCreate(task2, "Task 2", 128, NULL, 2, NULL);

   vTaskStartScheduler();

}