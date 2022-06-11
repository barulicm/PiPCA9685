from PiPCA9685.PiPCA9685 import PCA9685
import time

def main():
    pca = PCA9685()

    pca.set_pwm_freq(60)

    while True:
        pca.set_pwm(0, 0, 370)
        time.sleep(1)
        pca.set_pwm(0, 0, 415)
        time.sleep(1)
        pca.set_pwm(0, 0, 460)
        time.sleep(1)
        pca.set_pwm(0, 0, 415)
        time.sleep(1)

if __name__== "__main__":
    main()