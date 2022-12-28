#include <stdio.h>
#include "pico/stdlib.h"

#include "FreeRTOS.h"

#include "task.h"

#define PICO_DEFAULT_LED_R_PIN 17 // Xiao RP2040
#define PICO_DEFAULT_LED_G_PIN 16 // Xiao RP2040
#define PICO_DEFAULT_LED_B_PIN 25 // Xiao RP2040

static  TaskHandle_t handle_vBlinkTask_B = NULL;
static  TaskHandle_t handle_vBlinkTask_G = NULL;

void vBlinkTask_B() {
   uint16_t cnt = 0;
   for (;;) {
      gpio_put(PICO_DEFAULT_LED_B_PIN, 1);
      vTaskDelay(150);
      gpio_put(PICO_DEFAULT_LED_B_PIN, 0);
      vTaskDelay(150);
      printf("BBBBBBBBBBBBBBBB\n");
      if(++cnt>=10){
         // if(eTaskGetState(handle_vBlinkTask_B)!= eDeleted){
         //       printf("D-d-d-d-d-d--d-\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
         //       vTaskDelete(handle_vBlinkTask_B);
         // }
         vTaskResume(handle_vBlinkTask_G);
         printf("Into handle_vBlinkTask_G \n");
         cnt = 0;
         vTaskSuspend(handle_vBlinkTask_B);

      }
   }
}

void vBlinkTask_G() { 
   uint16_t cnt = 0;                                                                                                                                           
   for (;;) {
      gpio_put(PICO_DEFAULT_LED_G_PIN, 1);
      vTaskDelay(300);
      gpio_put(PICO_DEFAULT_LED_G_PIN, 0);
      vTaskDelay(300);
      printf("GGGGGGGGGGGGGGG\n");
      if(++cnt>=10){
         vTaskResume(handle_vBlinkTask_B);
         printf("Into handle_vBlinkTask_B \n");
         cnt = 0;
         vTaskSuspend(handle_vBlinkTask_G);
      }
   }
}

static void getTaskInfo(void * pvParameters){
   char pcTaskInfo[800];
   while(1){
      vTaskList(pcTaskInfo);
      printf("Name  Status Priority  Free_Stack PID\r\n");
      printf("%s\r\n" , pcTaskInfo);
      vTaskDelay(pdMS_TO_TICKS(4000));
   }
}

int main() {

   stdio_init_all();
   gpio_init(PICO_DEFAULT_LED_G_PIN);
   gpio_init(PICO_DEFAULT_LED_B_PIN);
   gpio_init(PICO_DEFAULT_LED_R_PIN);

   gpio_set_dir(PICO_DEFAULT_LED_G_PIN, GPIO_OUT);
   gpio_set_dir(PICO_DEFAULT_LED_B_PIN, GPIO_OUT);
   gpio_set_dir(PICO_DEFAULT_LED_R_PIN, GPIO_OUT);

   xTaskCreate(vBlinkTask_B, "Blink B Task", 120, NULL, 2, &handle_vBlinkTask_B);
   xTaskCreate(vBlinkTask_G, "Blink G Task", 120, NULL, 3, &handle_vBlinkTask_G);
   xTaskCreate(getTaskInfo, "Task info", 410, NULL, 1, NULL);

   vTaskSuspend(handle_vBlinkTask_G);

   vTaskStartScheduler();

}