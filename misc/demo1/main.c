#include <stdio.h>
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"

void vBlinkTask() {

   for (;;) {

      int a = 1;
      int b[100];

      gpio_put(PICO_DEFAULT_LED_PIN, 1);

      vTaskDelay(250);

      gpio_put(PICO_DEFAULT_LED_PIN, 0);

      vTaskDelay(250);

      // printf("Hello, world!\n");

      for(int i=0; i<100 ; i++){
         b[i]= a + 1;
      }
      
      printf("%d",b[0]);

      // printf("%d",uxTaskGetStackHighWaterMark(NULL));
      printf("%d\n",xPortGetFreeHeapSize());
      int *msg_ptr = (int *)pvPortMalloc(1024 * sizeof(int));
      if(msg_ptr==NULL){
         printf("RRR");
      }

      vTaskDelay(200 / portTICK_PERIOD_MS);

   }

}

int main() {

   stdio_init_all();
   gpio_init(PICO_DEFAULT_LED_PIN);

   gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

   xTaskCreate(vBlinkTask, "Blink Task", 1280, NULL, 1, NULL);

   vTaskStartScheduler();

}