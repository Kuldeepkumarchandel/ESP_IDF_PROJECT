#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#define MAX_APs 20


// From auth_mode code to string
static char* getAuthModeName(wifi_auth_mode_t auth_mode) {
	
	char *names[] = {"OPEN", "WEP", "WPA PSK", "WPA2 PSK", "WPA WPA2 PSK", "MAX"};
	return names[auth_mode];
}



// Empty infinite task
void loop_task(void *pvParameter)
{
    while(1) { 
		vTaskDelay(1000 / portTICK_PERIOD_MS);		
    }
}


void WiFi_scanner()
{
    // configure and run the scan process in blocking mode
    wifi_scan_config_t scan_config = {
        .ssid = 0,
        .bssid = 0,
        .channel = 0,
            .show_hidden = true
        };
    printf("Start scanning...");
    ESP_ERROR_CHECK(esp_wifi_scan_start(&scan_config, true));
    printf(" completed!\n");
    
    // get the list of APs found in the last scan
    uint16_t ap_num;
    wifi_ap_record_t ap_records[20];
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_num, ap_records));
    
    // print the list 
    printf("Found %d access points:\n", ap_num);

    printf("               SSID              | Channel | RSSI |   MAC \n\n");
    printf("----------------------------------------------------------------\n");
    for(int i = 0; i < ap_num; i++)
        printf("%32s | %7d | %4d   %2x:%2x:%2x:%2x:%2x:%2x   \n", ap_records[i].ssid, ap_records[i].primary, ap_records[i].rssi , *ap_records[i].bssid, *(ap_records[i].bssid+1), *(ap_records[i].bssid+2), *(ap_records[i].bssid+3), *(ap_records[i].bssid+4), *(ap_records[i].bssid+5));
    printf("----------------------------------------------------------------\n");   

    
    
}


static EventGroupHandle_t s_wifi_event_group;
void app_main()
{
	// initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) 
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    s_wifi_event_group = xEventGroupCreate();
    //Initialize the underlying TCP/IP stack
    ESP_ERROR_CHECK(esp_netif_init());
    //Create default event loop
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    /**
    * @brief Creates default WIFI STA. In case of any init error this API aborts.
    *
    * @note The API creates esp_netif object with default WiFi station config,
    * attaches the netif to wifi and registers default wifi handlers.
    *
    * @return pointer to esp-netif instance
    */
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    
    // Initialize WiFi
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_start() );
    ESP_ERROR_CHECK(ret);
    while(1)
    {
        WiFi_scanner();
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }

}