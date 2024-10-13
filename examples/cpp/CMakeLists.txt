cmake_minimum_required(VERSION 3.25)
project(example)

set(CMAKE_CXX_STANDARD 23)

find_package(PiPCA9685 REQUIRED)

add_executable(example-cpp main.cpp)
target_link_libraries(example-cpp PiPCA9685::PiPCA9685)
