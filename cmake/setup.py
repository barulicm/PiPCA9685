from distutils.core import setup

setup(
    name='PiPCA9685',
    packages=['PiPCA9685'],
    package_dir={'PiPCA9685':'PiPCA9685'},
    package_data={'PiPCA9685': ['*.so','*.a']}
)