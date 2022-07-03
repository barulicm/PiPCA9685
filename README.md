# PiPCA9685

PiPCA9685 provides an interface for controlling a PCA8695 chip from a Raspberry Pi in C++ and Python.

This library was originally designed to control servos with [Adafruit's PWM Hat](https://www.adafruit.com/product/2327). It was born out of a desire for C++ bindings, which Adafruit's library lacks.

## Installation

1. Before you begin, make sure your Pi has I2C enabled.

   1. Run `sudo raspi-config`
   2. Select "Interfacing Options"
   3. Enable I2C automatic loading

1. Clone repo

   ```bash
   git clone https://github.com/barulicm/PiPCA9685.git
   ```

1. Install dependencies from apt

   ```bash
   cd PiPCA9685
   xargs -a apt_dependencies.txt sudo apt-get install -y
   ```

1. Finally, build and install the library

   ```bash
   cmake -B build
   cmake --build build
   sudo cmake --install build
   cmake --build build --target install_python
   ```

**NOTE:** PiPCA9685 will default to installing the Python library for Python 3. If you'd like to use a different version, you can specify the version in the call to cmake.

```bash
cmake -DPYBIND11_PYTHON_VERIONS 2.7 ..
```

## Examples

You can find simple examples of how to use this library in C++ and Python in the _examples_ directory.

### C++

To build and run the C++ example, run the following commands in the `examples/cpp/` directory.

```bash
cmake -B build
cmake --build build
./build/example-cpp
```

### Python

To run the Python example, run the following command in the `examples/python/` directory.

```bash
python3 example.py
```

