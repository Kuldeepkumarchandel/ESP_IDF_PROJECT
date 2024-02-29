# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v4.4.4/components/bootloader/subproject"
  "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader"
  "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader-prefix"
  "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader-prefix/tmp"
  "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader-prefix/src"
  "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Data/GIT/ESP_IDF_PROJECT/Generate_random_number/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
