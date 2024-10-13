# PiPCA9685

PiPCA9685 provides an interface for controlling a PCA9685 chip from a Raspberry Pi in C++ and Python.

This library was originally designed to control servos with [Adafruit's PWM Hat](https://www.adafruit.com/product/2327). It was born out of a desire for C++ bindings, which Adafruit did not provide.

## Installation

1. Before you begin, make sure your Pi has I2C enabled.

   This step is not needed when using Ubuntu.

   1. Run `sudo raspi-config`
   1. Select "Interfacing Options"
   1. Enable I2C automatic loading

1. Clone repo

   ```bash
   git clone https://github.com/barulicm/PiPCA9685.git
   ```

1. Install dependencies from apt

   ```bash
   cd PiPCA9685
   xargs -a apt_dependencies.txt sudo apt-get install -y
   ```

   **Note:** On Ubuntu, you may need to enable [the universe repostiory](https://help.ubuntu.com/community/Repositories/Ubuntu) with the command below to find some of the needed packages. This is NOT needed on Raspberry Pi OS.

   ```bash
   sudo add-apt-repository universe
   ```

1. Build and install library

   ```bash
   sudo cmake --workflow --preset install
   ```

You can uninstall the library with this CMake command:

```bash
sudo cmake --workflow --preset uninstall
```

## Examples

You can find simple examples of how to use this library in C++ and Python in the [examples](examples) directory.

### C++

To build and run the C++ example, run the following commands in the `examples/cpp/` directory.

```bash
cmake --workflow --preset build
./build/example-cpp
```

### Python

To run the Python example, run the following command in the `examples/python/` directory.

```bash
python3 example.py
```
