| Supported Targets | ESP32 | ESP32-C3 | ESP32-S3 | ESP32-S2 | ESP32-H6 |
| ----------------- | ----- | -------- | -------- | -------- | -------- |

# ESP32 WiFi Scanner

This project demonstrates how to perform a WiFi scan using an ESP32 microcontroller and print the list of available WiFi networks.

## Requirements

- ESP development board
- ESP-IDF development environment
- USB cable for programming and powering the ESP Development Board

### Build and Flash

Build the project and flash it to the board, then run the monitor tool to view the serial output:

Run `idf.py -p PORT flash monitor` to build, flash, and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the Getting Started Guide for all the steps to configure and use the ESP-IDF to build projects.

* [ESP-IDF Getting Started Guide on ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)
* [ESP-IDF Getting Started Guide on ESP32-S2](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html)
* [ESP-IDF Getting Started Guide on ESP32-C3](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/get-started/index.html)

## Example Output
Note that the output, in particular the order of the output, may vary depending on the environment.

Console output after scanning successfully:

```
Start scanning... completed!
Found 9 access points:
               SSID              | Channel | RSSI |   MAC

----------------------------------------------------------------
                 Rudra_Deep_4GHz |       8 |  -54   a8:e2: 7:24:bc:fa   
                Airtel_chan_9357 |       1 |  -77   30:4f:75:e2: e:c0
                       Hashmi 4G |       2 |  -77   b4:b0:24:eb:70:e1   
         WI_FIBER(7011975223)_4G |      11 |  -80   b8:b7:db:2d:7d:ad
                           Akash |       5 |  -82   1c:ef: 3: d:ba:c5
                   JioPrivateNet |       6 |  -83    0: 6:ae:f8:f0:37   
                   Hammad's home |      11 |  -83   e8:65:d4:83:26:d0
                Airtel_vish_7688 |      10 |  -84   20: c:86:7a:30: 0   
                              NS |      10 |  -90   c4:70: b:d1:ee:a8   
----------------------------------------------------------------
```

## Troubleshooting

For any technical queries, please open an [issue](https://github.com/espressif/esp-idf/issues) on GitHub. We will get back to you soon.
