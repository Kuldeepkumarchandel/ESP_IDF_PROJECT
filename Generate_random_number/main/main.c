#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define DR_REG_RNG_BASE                        0x3ff75144

// Main task
void main_task(void *pvParameter)
{
	while(1) {
		
		// wait 5 second
		vTaskDelay(5000 / portTICK_RATE_MS);
		// get a new random number and print it
		uint32_t randomNumber = READ_PERI_REG(DR_REG_RNG_BASE);
		printf("1.random number: %u\n", randomNumber);
		// Second metrhod
		srand(randomNumber);  // providing seed value
		printf("2.random number: %u\n", rand());   // Get random value
	} 
}


// Main application
void app_main()
{
	// start the main task
    xTaskCreate(&main_task, "main_task", 2048, NULL, 5, NULL);
}

