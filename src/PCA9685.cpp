#include "PiPCA9685/PCA9685.h"
#include <unistd.h>
#include <cmath>
#include "Constants.h"
#include "I2CPeripheral.h"

namespace PiPCA9685 {

PCA9685::PCA9685(const std::string &device, int address) {
  i2c_dev = std::make_unique<I2CPeripheral>(device, address);
  
  set_all_pwm(0,0);
  i2c_dev->WriteRegisterByte(MODE2, OUTDRV);
  i2c_dev->WriteRegisterByte(MODE1, ALLCALL);
  usleep(5'000);
  auto mode1_val = i2c_dev->ReadRegisterByte(MODE1);
  mode1_val &= ~SLEEP;
  i2c_dev->WriteRegisterByte(MODE1, mode1_val);
  usleep(5'000);
}

PCA9685::~PCA9685() = default;

void PCA9685::set_pwm_freq(const double freq_hz) {
  frequency = freq_hz;

  auto prescaleval = 2.5e7; //    # 25MHz
  prescaleval /= 4096.0; //       # 12-bit
  prescaleval /= freq_hz;
  prescaleval -= 1.0;

  auto prescale = static_cast<int>(std::round(prescaleval));

  const auto oldmode = i2c_dev->ReadRegisterByte(MODE1);

  auto newmode = (oldmode & 0x7F) | SLEEP;

  i2c_dev->WriteRegisterByte(MODE1, newmode);
  i2c_dev->WriteRegisterByte(PRESCALE, prescale);
  i2c_dev->WriteRegisterByte(MODE1, oldmode);
  usleep(5'000);
  i2c_dev->WriteRegisterByte(MODE1, oldmode | RESTART);
}

void PCA9685::set_pwm(const int channel, const uint16_t on, const uint16_t off) {
  const auto channel_offset = 4 * channel;
  i2c_dev->WriteRegisterByte(LED0_ON_L+channel_offset, on & 0xFF);
  i2c_dev->WriteRegisterByte(LED0_ON_H+channel_offset, on >> 8);
  i2c_dev->WriteRegisterByte(LED0_OFF_L+channel_offset, off & 0xFF);
  i2c_dev->WriteRegisterByte(LED0_OFF_H+channel_offset, off >> 8);
}

void PCA9685::set_all_pwm(const uint16_t on, const uint16_t off) {
  i2c_dev->WriteRegisterByte(ALL_LED_ON_L, on & 0xFF);
  i2c_dev->WriteRegisterByte(ALL_LED_ON_H, on >> 8);
  i2c_dev->WriteRegisterByte(ALL_LED_OFF_L, off & 0xFF);
  i2c_dev->WriteRegisterByte(ALL_LED_OFF_H, off >> 8);
}

void PCA9685::set_pwm_ms(const int channel, const double ms) {
  auto period_ms = 1000.0 / frequency;
  auto bits_per_ms = 4096 / period_ms;
  auto bits = ms * bits_per_ms;
  set_pwm(channel, 0, bits);
}

}  // namespace PiPCA9685
