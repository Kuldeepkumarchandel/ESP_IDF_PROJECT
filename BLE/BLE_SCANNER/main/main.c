#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"

#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gatt_common_api.h"


// array of found devices
#define MAX_DISCOVERED_DEVICES 50
esp_bd_addr_t discovered_devices[MAX_DISCOVERED_DEVICES];
int discovered_devices_num = 0;

// scan parameters
static esp_ble_scan_params_t ble_scan_params = {
		.scan_type              = BLE_SCAN_TYPE_ACTIVE,
		.own_addr_type          = BLE_ADDR_TYPE_PUBLIC,
		.scan_filter_policy     = BLE_SCAN_FILTER_ALLOW_ALL,
		.scan_interval          = 0x50,
		.scan_window            = 0x30
	};

// check if the device was already discovered
bool alreadyDiscovered(esp_bd_addr_t address) {

	bool found = false;
	
	for(int i = 0; i < discovered_devices_num; i++) {
		
		for(int j = 0; j < ESP_BD_ADDR_LEN; j++)
			found = (discovered_devices[i][j] == address[j]);
		
		if(found) break;
	}
	
	return found;
}

// add a new device to the list
void addDevice(esp_bd_addr_t address) {
	
	discovered_devices_num++;
	if(discovered_devices_num > MAX_DISCOVERED_DEVICES) return;

	for(int i = 0; i < ESP_BD_ADDR_LEN; i++)
		discovered_devices[discovered_devices_num - 1][i] = address[i];
}

// GAP callback
static void esp_gap_cb(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param)
{
    switch (event) {
		
		case ESP_GAP_BLE_SCAN_PARAM_SET_COMPLETE_EVT: 
				
			ESP_LOGI("BLE_SCAN","ESP_GAP_BLE_SCAN_PARAM_SET_COMPLETE_EVT\n");
			if(param->scan_param_cmpl.status == ESP_BT_STATUS_SUCCESS) {
				ESP_LOGI("BLE_SCAN","Scan parameters set, start scanning for 10 seconds\n\n");
				esp_ble_gap_start_scanning(10);
			}
			else ESP_LOGI("BLE_SCAN","Unable to set scan parameters, error code %d\n\n", param->scan_param_cmpl.status);
			break;
		
		case ESP_GAP_BLE_SCAN_START_COMPLETE_EVT:
			
			ESP_LOGI("BLE_SCAN","ESP_GAP_BLE_SCAN_START_COMPLETE_EVT\n");
			if(param->scan_start_cmpl.status == ESP_BT_STATUS_SUCCESS) {
				ESP_LOGI("BLE_SCAN","Scan started\n\n");
			}
			else ESP_LOGI("BLE_SCAN","Unable to start scan process, error code %d\n\n", param->scan_start_cmpl.status);
			break;
		
		case ESP_GAP_BLE_SCAN_RESULT_EVT:
			
			if(param->scan_rst.search_evt == ESP_GAP_SEARCH_INQ_RES_EVT) {
				
				if(!alreadyDiscovered(param->scan_rst.bda)) {
					
					ESP_LOGI("BLE_SCAN","ESP_GAP_BLE_SCAN_RESULT_EVT\n");
					printf("Device found: ADDR=");
					for(int i = 0; i < ESP_BD_ADDR_LEN; i++) {
						printf("%02X", param->scan_rst.bda[i]);
						if(i != ESP_BD_ADDR_LEN -1) printf(":");
					}
					
					printf("\n");
					addDevice(param->scan_rst.bda);
				}
				
			}
			else if(param->scan_rst.search_evt == ESP_GAP_SEARCH_INQ_CMPL_EVT)
				ESP_LOGI("BLE_SCAN","Scan complete\n\n");
			break;
		
		default:
		
			ESP_LOGI("BLE_SCAN","Event %d unhandled\n\n", event);
			break;
	}
}


void app_main() {
	
	ESP_LOGI("BLE_SCAN","BT scan\n\n");

	  esp_err_t ret;

    // Initialize NVS.
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT));

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ret = esp_bt_controller_init(&bt_cfg);
    if (ret) {
        ESP_LOGE("BLE_SCAN", "%s initialize controller failed: %s", __func__, esp_err_to_name(ret));
        return;
    }

    ret = esp_bt_controller_enable(ESP_BT_MODE_BLE);
    if (ret) {
        ESP_LOGE("BLE_SCAN", "%s enable controller failed: %s", __func__, esp_err_to_name(ret));
        return;
    }
   
    ret = esp_bluedroid_init();
    if (ret) {
        ESP_LOGE("BLE_SCAN", "%s init bluetooth failed: %s", __func__, esp_err_to_name(ret));
        return;
    }
    ret = esp_bluedroid_enable();
    if (ret) {
        ESP_LOGE("BLE_SCAN", "%s enable bluetooth failed: %s", __func__, esp_err_to_name(ret));
        return;
    }

    ret = esp_ble_gap_register_callback(esp_gap_cb);
    if (ret){
        ESP_LOGE("BLE_SCAN", "gap register error, error code = %x", ret);
        return;
    }
	// configure scan parameters
	esp_ble_gap_set_scan_params(&ble_scan_params);
}