#ifndef RPY_PWM_HAT_CONSTANTS_H
#define RPY_PWM_HAT_CONSTANTS_H
#include <cstdint>

namespace PiPCA9685 {

// Registers/etc:
constexpr uint8_t MODE1              = 0x00;
constexpr uint8_t MODE2              = 0x01;
constexpr uint8_t SUBADR1            = 0x02;
constexpr uint8_t SUBADR2            = 0x03;
constexpr uint8_t SUBADR3            = 0x04;
constexpr uint8_t PRESCALE           = 0xFE;
constexpr uint8_t LED0_ON_L          = 0x06;
constexpr uint8_t LED0_ON_H          = 0x07;
constexpr uint8_t LED0_OFF_L         = 0x08;
constexpr uint8_t LED0_OFF_H         = 0x09;
constexpr uint8_t ALL_LED_ON_L       = 0xFA;
constexpr uint8_t ALL_LED_ON_H       = 0xFB;
constexpr uint8_t ALL_LED_OFF_L      = 0xFC;
constexpr uint8_t ALL_LED_OFF_H      = 0xFD;

// Bits:
constexpr uint8_t RESTART            = 0x80;
constexpr uint8_t SLEEP              = 0x10;
constexpr uint8_t ALLCALL            = 0x01;
constexpr uint8_t INVRT              = 0x10;
constexpr uint8_t OUTDRV             = 0x04;

}  // namespace PiPCA9685

#endif //RPY_PWM_HAT_CONSTANTS_H
