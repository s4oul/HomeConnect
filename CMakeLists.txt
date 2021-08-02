cmake_minimum_required(VERSION 3.18)
project(HomeConnect VERSION 1.0)
enable_language(C)
enable_language(CXX)

option(TARGET_LINUX "Target Linux" ON)
option(TARGET_APPLE "Target MacOs" OFF)
option(TARGET_RASPBERRY_PI_3 "Target Raspberry Pi 3" OFF)
option(TARGET_RASPBERRY_PICO "Target Raspberry Pico" OFF)
option(SYNCHRONE "Bibliotheque Synchrone" OFF)

add_compile_options(-W -Wall -Wextra -Wconversion-null)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXE_NAME_HOME_CONNECT home_connect)
set(EXE_NAME_FAN_SMART fan_smart)
set(CMAKE_INSTALL_PREFIX /usr)

if(SYNCHRONE)
    add_definitions(-D__SYNCHRONE)
endif()

if(TARGET_LINUX)
    add_definitions(-D__LINUX)

elseif(TARGET_RASPBERRY_PI_3)
    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    set(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
    set(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")

    add_definitions(-D__RASPBERRY)
endif()

add_executable(${EXE_NAME_HOME_CONNECT})
add_executable(${EXE_NAME_FAN_SMART})
add_subdirectory(homeconnect)
add_subdirectory(fansmart)

message("####################")
message("CMAKE_CXX_STANDARD          : ${CMAKE_CXX_STANDARD}")
message("CMAKE_C_COMPILER            : ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER          : ${CMAKE_CXX_COMPILER}")
message("********************")
message("TARGET_LINUX                : ${TARGET_LINUX}")
message("TARGET_APPLE                : ${TARGET_APPLE}")
message("TARGET_RASPBERRY_PI_3       : ${TARGET_RASPBERRY_PI_3}")
message("TARGET_RASPBERRY_PICO       : ${TARGET_RASPBERRY_PICO}")
message("~~~~~~~~~~~~~~~~~~~~")
message("SYNCHRONE                   : ${SYNCHRONE}")
message("####################")
