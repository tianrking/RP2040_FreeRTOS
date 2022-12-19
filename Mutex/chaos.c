#include <stdio.h>
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"


static QueueHandle_t xQueue = NULL;

void task1(void *pvParameters)
{
   char ch = '1';
   while (true)
   {
      for(int i=1;i<10;i++){
         putchar(ch);
      }
      puts("");
   }  
}

void task2(void *pvParameters)
{
   char ch = '2';
   while (true)
   {
      for(int i=1;i<10;i++){
         putchar(ch);
      }
      puts("");
   }  
}

int main() {

   stdio_init_all();

   gpio_init(PICO_DEFAULT_LED_PIN);
   gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

   // xQueue = xQueueCreate(1,sizeof(uint));
   xTaskCreate(task1, "Task 1", 256, NULL, 1, NULL);
   xTaskCreate(task2, "Task 2", 256, NULL, 1, NULL);

   vTaskStartScheduler();

}

