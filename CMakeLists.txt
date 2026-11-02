cmake_minimum_required(VERSION 3.16)

project(a_bad_way_native LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(JNI REQUIRED)

add_library(NativeBridge SHARED
    src/main/native/native.cpp
)

target_include_directories(NativeBridge PRIVATE
    ${JNI_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/target/native-headers
)

set_target_properties(NativeBridge PROPERTIES
    OUTPUT_NAME "NativeBridge"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/native"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/target/native"
)
