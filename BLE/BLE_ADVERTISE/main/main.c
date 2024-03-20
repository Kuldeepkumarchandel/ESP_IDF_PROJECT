#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "string.h"
#include "nvs_flash.h"
#include "esp_err.h"
#include "esp_log.h"

#include "esp_bt.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"

static esp_ble_adv_params_t ble_adv_params = {
	
	.adv_int_min = 0x20,
	.adv_int_max = 0x40,
	.adv_type = ADV_TYPE_NONCONN_IND,
	.own_addr_type  = BLE_ADDR_TYPE_PUBLIC,
	.channel_map = ADV_CHNL_ALL,
	.adv_filter_policy  = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

static esp_ble_adv_data_t adv_data = {
	
	.include_name = true,
	.flag = ESP_BLE_ADV_FLAG_LIMIT_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT,
	.appearance = 384,
    .manufacturer_len = strlen("ESP ADVERTYISEMENT DEMO"),
    .p_manufacturer_data = (uint8_t*)"ESP ADVERTYISEMENT DEMO",
};

// GAP callback
static void esp_gap_cb(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param)
{
    switch (event) {
		
		case ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT: 
				
			ESP_LOGI("BLE_ADVERTISE","ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT\n");
			esp_ble_gap_start_advertising(&ble_adv_params);
			break;		
		
		case ESP_GAP_BLE_ADV_START_COMPLETE_EVT:
			
			ESP_LOGI("BLE_ADVERTISE","ESP_GAP_BLE_ADV_START_COMPLETE_EVT\n");
			if(param->adv_start_cmpl.status == ESP_BT_STATUS_SUCCESS) {
				ESP_LOGI("BLE_ADVERTISE","Advertising started\n\n");
			}
			else ESP_LOGI("BLE_ADVERTISE","Unable to start advertising process, error code %d\n\n", param->scan_start_cmpl.status);
			break;
	
		default:
		
			ESP_LOGI("BLE_ADVERTISE","Event %d unhandled\n\n", event);
			break;
	}
}

void Bluetooth_data_advertisement()
{
    esp_err_t ret = esp_ble_gap_config_adv_data(&adv_data);
    if (ret){
        printf( "config adv data failed, error code = %x\n", ret);
    }
}

void app_main() {
	
	ESP_LOGI("BLE_ADVERTISE","BT ADVERTISEMENT\n\n");

	// initialize nvs
	ESP_ERROR_CHECK(nvs_flash_init());
	ESP_LOGI("BLE_ADVERTISE","- NVS init ok\n");
	
	// release memory reserved for classic BT (not used)
	ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT));
	ESP_LOGI("BLE_ADVERTISE","- Memory for classic BT released\n");
	
	// initialize the BT controller with the default config
	esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    esp_bt_controller_init(&bt_cfg);
	ESP_LOGI("BLE_ADVERTISE","- BT controller init ok\n");
	
	// enable the BT controller in BLE mode
    esp_bt_controller_enable(ESP_BT_MODE_BLE);
	ESP_LOGI("BLE_ADVERTISE","- BT controller enabled in BLE mode\n");
	
	// initialize Bluedroid library
    esp_bluedroid_config_t bluedroid_cfg = BT_BLUEDROID_INIT_CONFIG_DEFAULT();
    esp_bluedroid_init_with_cfg(&bluedroid_cfg);
    esp_bluedroid_enable();
	ESP_LOGI("BLE_ADVERTISE","- Bluedroid initialized and enabled\n");
	
	// register GAP callback function
	ESP_ERROR_CHECK(esp_ble_gap_register_callback(esp_gap_cb));
	ESP_LOGI("BLE_ADVERTISE","- GAP callback registered\n\n");
	
	// configure the adv data
	ESP_ERROR_CHECK(esp_ble_gap_set_device_name("ESP32_BLE"));
	ESP_ERROR_CHECK(esp_ble_gap_config_adv_data(&adv_data));
	ESP_LOGI("BLE_ADVERTISE","- ADV data configured\n\n");
}