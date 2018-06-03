cmake_minimum_required(VERSION 3.1)
project(example)

set(CMAKE_CXX_STANDARD 14)

find_package(PiPCA9685 REQUIRED)

add_executable(example-cpp main.cpp)
target_link_libraries(example-cpp ${PiPCA9685_LIBRARY})
