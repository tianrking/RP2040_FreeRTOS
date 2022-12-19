#include <stdio.h>
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"


static QueueHandle_t xQueue = NULL;

void vBlinkTask(void *pvParameters) {

   uint uIValueToSend = 0;
   for (;;) {

      gpio_put(PICO_DEFAULT_LED_PIN, 1);
      uIValueToSend = 1;
      xQueueSend(xQueue,&uIValueToSend,0U);
      vTaskDelay(500);

      gpio_put(PICO_DEFAULT_LED_PIN, 0);
      uIValueToSend = 0;
      xQueueSend(xQueue,&uIValueToSend,0U);
      vTaskDelay(500);

   }
}

void usb_task(void *pvParameters){
   uint uIReceivedValue ;

   while(1){
      xQueueReceive(xQueue,&uIReceivedValue,portMAX_DELAY);
      if (uIReceivedValue == 1){
         printf("Led On");
      }
      if (uIReceivedValue == 0){
         printf("Led Off");
      }

   }
}

int main() {

   stdio_init_all();
   gpio_init(PICO_DEFAULT_LED_PIN);

   gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);


   xQueue = xQueueCreate(1,sizeof(uint));
   xTaskCreate(vBlinkTask, "Blink Task", 256, NULL, 1, NULL);
   xTaskCreate(usb_task, "USB Task", 256, NULL, 1, NULL);

   vTaskStartScheduler();

}

