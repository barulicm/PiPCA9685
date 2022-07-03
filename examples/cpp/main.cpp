#include <unistd.h>
#include <PiPCA9685/PCA9685.h>

int main() {
  
  PiPCA9685::PCA9685 pca{};

  pca.set_pwm_freq(60.0);
  
  while(true) {
    pca.set_pwm(0, 0, 370);
    usleep(1'000'000);
    pca.set_pwm(0, 0, 415);
    usleep(1'000'000);
    pca.set_pwm(0, 0, 460);
    usleep(1'000'000);
    pca.set_pwm(0, 0, 415);
    usleep(1'000'000);
  }
}