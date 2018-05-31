# PiPCA9685

PiPCA9685 provides an interface for controlling a PCA8695 chip from a Raspberry Pi in C++ and Python.

This library was originally designed to control servos with [Adafruit's PWM Hat](https://www.adafruit.com/product/2327). It was born out of a desire for C++ bindings, which Adafruit's library lacks.

## Dependencies

This library uses Gordon Henderson's [WiringPi](http://wiringpi.com/) to simplify the I2C code.

## Installation

Before you begin, make sure your Pi has I2C enabled.
   1. `sudo raspi-config`
   2. Select "Interfacing Options"
   3. Enable I2C automatic loading
   
Install WiringPi, following Gordon's instructions [here](http://wiringpi.com/download-and-install/).

Finally, clone, build, and install this library

```bash
git clone 
cd PiPCA9685
mkdir build && cd build
cmake ..
make
sudo make install
make python_install
```

PiPCA9685 will default to installing the Python library for Python 3. If you'd like to use a different version, you can specify the version in the call to cmake.

```bash
cmake -DPYTHON_VERIONS 2.7 ..
```

## Examples

You can find simple examples of how to use this library in C++ and Python in the _examples_ directory.
