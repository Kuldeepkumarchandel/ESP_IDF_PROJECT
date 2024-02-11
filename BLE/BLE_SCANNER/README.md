| Supported Targets | ESP32 | ESP32-C3 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- |

# ESP32 BLE Scanner

ESP32 BLE Scanner is a simple Bluetooth Low Energy (BLE) scanning application developed using ESP32S3 microcontroller. It scans for nearby BLE devices and logs the discovered devices' addresses.

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

## Acknowledgments

Special thanks to Espressif Systems for providing the ESP32S3 microcontroller and the associated development tools and libraries.
