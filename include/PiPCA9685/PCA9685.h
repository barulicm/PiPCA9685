#ifndef RPY_PWM_HAT_PCA9685_H
#define RPY_PWM_HAT_PCA9685_H

#include <string>

class PCA9685 {
public:
    explicit PCA9685(const std::string &device = "/dev/i2c-1", int address = 0x40);

    void set_pwm_freq(double freq_hz);

    void set_pwm(int channel, uint16_t on, uint16_t off);

    void set_all_pwm(uint16_t on, uint16_t off);

    void set_pwm_ms(int channel, double ms);

private:
    int i2c_fd;
    
    // Default frequency pulled from PCA9685 datasheet.
    double frequency = 200.0;

    void check_ret(int ret, std::string msg = "");

};

#endif //RPY_PWM_HAT_PCA9685_H
