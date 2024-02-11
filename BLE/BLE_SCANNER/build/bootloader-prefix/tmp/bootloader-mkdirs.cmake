# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v4.4.4/components/bootloader/subproject"
  "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader"
  "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader-prefix"
  "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader-prefix/tmp"
  "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader-prefix/src/bootloader-stamp"
  "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader-prefix/src"
  "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/KULDEEP/SVN/ESP_DEVELOPMENT/GIT/ESP_IDF_PROJECT/BLE/BLE_SCANNER/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
