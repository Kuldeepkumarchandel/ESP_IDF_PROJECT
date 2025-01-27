# ESP32 Getting Started with ESP-IDF

This repository provides a step-by-step guide to getting started with the **ESP32** microcontroller using the **Espressif IoT Development Framework (ESP-IDF)**. Whether new to ESP32 or IoT development, this guide will help you set up your environment and build your first project.

---

## Table of Contents
- [Prerequisites](#prerequisites)
- [Setting Up the Development Environment](#setting-up-the-development-environment)
- [Building and Flashing Your First Project](#building-and-flashing-your-first-project)
- [Features of ESP-IDF](#features-of-esp-idf)
- [Troubleshooting](#troubleshooting)
- [Additional Resources](#additional-resources)

---

## Prerequisites

### Hardware
- ESP32 Development Board (e.g., ESP32-DevKitC, ESP32-WROOM).
- USB cable to connect the board to your computer.

![ESP32 Development Board](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/_images/esp32-devkitm-1-v1-annotated-photo.png)

### Software
- A computer running Windows, macOS, or Linux.
- Python 3.6 or later.
- Git for version control.

### To start using ESP -IDF on ESP32, install the following software:
  - **Toolchain** to compile code for ESP32
  - **Build tools** - CMake and Ninja to build a full Application for ESP32
  - **ESP-IDF** that essentially contains API(software libraries and source code) for **ESP32** and script to operate the Toolchain

    ![ESP32_Program_script](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/_images/what-you-need.png)

---

## Setting Up the Development Environment

1. Clone the ESP-IDF repository:
   ```bash
   git clone --recursive https://github.com/espressif/esp-idf.git
   ```
2. Navigate to the `esp-idf` directory:
   ```bash
   cd esp-idf
   ```
3. Run the installation script for your operating system:
   - **Windows:** `install.bat`
   - **macOS/Linux:**
     ```bash
     ./install.sh
     ```
4. Add ESP-IDF tools to your path:
   ```bash
   source export.sh
   ```
---

## Features of ESP-IDF

![ESP-IDF-PINOUT](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32/_images/esp32_devkitC_v4_pinlayout.png)

ESP-IDF provides a wide range of features, including:
- **Wi-Fi and Bluetooth APIs**
- **Timers and Interrupts**
- **FreeRTOS Support for Multitasking**
- **Single or Dual-Core 32-bit LX6 Microprocessor with clock frequency up to 240 MHz.**
- **520 KB of SRAM, 448 KB of ROM, and 16 KB of RTC SRAM.**
- **Supports 802.11 b/g/n Wi-Fi connectivity with speeds up to 150 Mbps.**
- **Support for both Classic Bluetooth v4.2 and BLE specifications.**
- **GPIO Control - 34 Programmable GPIOs.**
- **Up to 18 channels of 12-bit SAR ADC and 2 channels of 8-bit DAC**
- **Peripheral Drivers (I2C, SPI, UART, ADC, PWM) - Serial Connectivity includes 4 x SPI, 2 x I2C, 2 x I2S, 3 x UART.**
- **1 Host controller for SD/SDIO/MMC and 1 Slave controller for SDIO/SPI.**
- **Motor PWM and up to 16 channels of LED PWM.**
- **Secure Boot and Flash Encryption.**

![ESP32 Features](https://github.com/Kuldeepkumarchandel/ESP_IDF_PROJECT/blob/main/screenshoot/features_images.png)

---

## Building and Flashing Your First Project

1. Navigate to the `hello_world` example:

   ```bash
   cd examples/get-started/hello_world
   ```

2. Copy the project to a new directory for customization:
   ```bash
   cp -r hello_world ~/esp_projects/my_first_project
   cd ~/esp_projects/my_first_project
   ```
3. You can open a project using **Visual Studio Code**

    Create the example project hello_world: **In VSCODE->"View"->"Command Panel"->Enter: Show Examples projects->Select
      Use current ESP-IDF(E:\ESP32-IDFlesplesp-idf)->The example ESP-IDF Examples pops up, select get-started->hello_world**

    Create project using the example hello world->Select the path to save the example

   ![ESP32 Features](https://github.com/Kuldeepkumarchandel/ESP_IDF_PROJECT/blob/main/screenshoot/Hello_world.png)

   
5. Configure the project:
   ```bash
   idf.py menuconfig
   ```
   ![Menuconfig Tool](https://github.com/Kuldeepkumarchandel/ESP_IDF_PROJECT/blob/main/screenshoot/manuconfig.png)

6. Code

   ```bash
       void app_main(void)
       {
          printf("Hello world!\n");
      
       }

   ```

7. Build the project:
   ```bash
   idf.py build
   ```
  

8. Flash the firmware to the ESP32:
   ```bash
   idf.py -p [PORT] flash
   ```
9. Monitor the serial output:
   ```bash
   idf.py monitor
   ```
    ![Build Output](https://github.com/Kuldeepkumarchandel/ESP_IDF_PROJECT/blob/main/screenshoot/OUTPUT.png)
   
   Press `Ctrl+]` to exit the monitor.

---
Example Video Link 

[Hello World](https://www.youtube.com/watch?v=dN8UAwucMlY&t=4s)


## Troubleshooting

- **Build Errors:** Ensure all dependencies are installed and environment variables are correctly set.
- **Serial Port Issues:** Verify the port and ensure no other application uses it.
- **Flashing Errors:** Place the ESP32 in flashing mode by holding the BOOT button if necessary.

---

## Additional Resources

- [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/)
- [ESP32 Forum](https://esp32.com/)
- [GitHub Repository](https://github.com/espressif/esp-idf)

---

Happy coding with ESP32 and ESP-IDF!
