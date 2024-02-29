| Supported Targets | ESP32 | ESP32-C3 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- |

# ESP Microcontroller BLE Scanner with their Name

BLE Scanner is a simple Bluetooth Low Energy (BLE) scanning application developed using ESP32S3 microcontroller. It scans for nearby BLE devices and logs the discovered devices addresses as well their Names.

## Features

- **BLE Scanning:** Utilizes the ESP32's BLE capabilities to scan for nearby BLE devices.
- **Device Discovery:** Logs the addresses of discovered BLE devices and avoids duplicate entries.
- **Customizable Scan Parameters:** Allows customization of BLE scan parameters such as scan interval and scan window.
- **Bluetooth Initialization:** Initializes the ESP32's Bluetooth controller and enables BLE mode.
- **Error Handling:** Provides error logging for various initialization and scanning stages.

## Usage

1. **Hardware Setup:**
   - Connect the ESP32S3 microcontroller to the necessary peripherals and power source.

2. **Code Compilation and Flashing:**
   - Compile the provided code using the appropriate toolchain and flash it onto the ESP32S3 microcontroller.
   - Ensure that the required libraries and dependencies are properly installed and configured.

3. **Running the Application:**
   - Once the code is flashed onto the ESP32S3, the BLE scanner will start automatically.
   - The application will log any discovered BLE devices' addresses in the console output.


## Dependencies

- FreeRTOS
- ESP-IDF (Espressif IoT Development Framework)
- ESP32 BLE Stack


## How to Use Example

Before project configuration and build, be sure to set the correct chip target using:

```bash
idf.py set-target <chip_name>
```

### Hardware Required

* A development board with ESP32/ESP32-C3/ESP32-S3 SoC (e.g., ESP32-DevKitC, ESP-WROVER-KIT, etc.)
* A USB cable for Power supply and programming

### Build and Flash

Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)


## Example Output

I (0) cpu_start: App cpu up.
I (321) cpu_start: Pro cpu start user code
I (321) cpu_start: cpu freq: 160000000
I (321) cpu_start: Application information:
I (324) cpu_start: Project name:     BLE_SCAN
I (329) cpu_start: App version:      8fafff1-dirty
I (334) cpu_start: Compile time:     Mar  1 2024 00:55:23
I (340) cpu_start: ELF file SHA256:  cda383349f9c2803...
I (346) cpu_start: ESP-IDF:          v4.4.4-dirty
I (352) heap_init: Initializing. RAM available for dynamic allocation:
I (359) heap_init: At 3FC9D9F0 len 0004BD20 (303 KiB): D/IRAM
I (365) heap_init: At 3FCE9710 len 00005724 (21 KiB): STACK/DRAM
I (372) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
I (378) heap_init: At 600FE000 len 00002000 (8 KiB): RTCRAM
I (385) spi_flash: detected chip: gd
I (389) spi_flash: flash io: dio
I (394) coexist: coexist rom version e7ae62f
I (398) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (418) BLE_SCAN: BT scan


I (428) BT_INIT: BT controller compile version [02bfb7f]
I (428) phy_init: phy_version 540,a5d905b,Oct 20 2022,19:36:11
I (468) system_api: Base MAC address is not set
I (468) system_api: read default base MAC address from EFUSE
I (468) BT_INIT: Bluetooth MAC: 84:f7:03:c0:44:e2

I (518) BLE_SCAN: ESP_GAP_BLE_SCAN_PARAM_SET_COMPLETE_EVT

I (518) BLE_SCAN: Scan parameters set, start scanning for 10 seconds


I (518) BLE_SCAN: ESP_GAP_BLE_SCAN_START_COMPLETE_EVT

I (518) BLE_SCAN: Scan started


I (588) BLE_SCAN: ESP_GAP_BLE_SCAN_RESULT_EVT

Device found: ADDR=0D:14:3B:39:F6:A0
I (588) BLE_SCAN: ESP_GAP_BLE_SCAN_RESULT_EVT

Device found: ADDR=5C:B4:01:55:F0:61
I (868) BLE_SCAN: ESP_GAP_BLE_SCAN_RESULT_EVT

Device found: ADDR=7E:3C:0F:C2:C9:75     Device_FULL NAME = DESKTOP-3GEU9A8
I (938) BLE_SCAN: ESP_GAP_BLE_SCAN_RESULT_EVT

Device found: ADDR=70:B1:B0:71:3C:82     Device_FULL NAME = KULDEEP
I (1018) BLE_SCAN: ESP_GAP_BLE_SCAN_RESULT_EVT

Device found: ADDR=1F:9E:B0:FD:A7:D7     Device_FULL NAME = ESP_GATTS_DEMO
I (2128) BLE_SCAN: ESP_GAP_BLE_SCAN_RESULT_EVT

Device found: ADDR=E3:F1:2C:C6:1F:F8
I (10518) BLE_SCAN: Scan complete

## Acknowledgments

Special thanks to Espressif Systems for providing the ESP32S3 microcontroller and the associated development tools and libraries.
