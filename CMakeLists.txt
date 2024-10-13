cmake_minimum_required(VERSION 3.25)
project(PiPCA9685 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)

#
# Dependencies
#

find_package(Python COMPONENTS Interpreter Development REQUIRED)
message(STATUS "Using Python interpreter: ${Python_EXECUTABLE}")

find_package(pybind11 REQUIRED)

#
# LIBRARY
#

add_library(PiPCA9685_cpp
    src/PCA9685.cpp
    src/I2CPeripheral.cpp
)
target_sources(PiPCA9685_cpp
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
    include/PiPCA9685/PCA9685.h
)
target_link_libraries(PiPCA9685_cpp i2c)
set_property(TARGET PiPCA9685_cpp PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(PiPCA9685_cpp PROPERTIES
    OUTPUT_NAME PiPCA9685
    EXPORT_NAME PiPCA9685
)

add_library(PiPCA9685::PiPCA9685 ALIAS PiPCA9685_cpp)

#
# PYTHON BINDINGS
#

pybind11_add_module(PiPCA9685_python src/PCA9685-Python.cpp)
set_target_properties(PiPCA9685_python PROPERTIES OUTPUT_NAME PiPCA9685)
target_link_libraries(PiPCA9685_python PRIVATE PiPCA9685_cpp)

#
# INSTALLATION
#

include(GNUInstallDirs)

install(TARGETS PiPCA9685_cpp
    EXPORT PiPCA9685_export
    FILE_SET HEADERS
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(TARGETS PiPCA9685_python
    DESTINATION ${Python_SITEARCH}
)

install(EXPORT PiPCA9685_export
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/PiPCA9685
    NAMESPACE PiPCA9685::
    FILE PiPCA9685Config.cmake
)

if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
