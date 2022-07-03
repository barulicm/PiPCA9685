#ifndef PIPCA9685_I2CPERIPHERAL_H
#define PIPCA9685_I2CPERIPHERAL_H

#include <cstdint>
#include <string>

namespace PiPCA9685 {

class I2CPeripheral {
public:
  I2CPeripheral(const std::string& device, const uint8_t address);
  ~I2CPeripheral();

  void WriteRegisterByte(const uint8_t register_address, const uint8_t value);

  uint8_t ReadRegisterByte(const uint8_t register_address);

private:
  int bus_fd;

  void OpenBus(const std::string& device);
  void ConnectToPeripheral(const uint8_t address);

};

}  // namespace PiPCA9685

#endif  // PIPCA9685_I2CPERIPHERAL_H