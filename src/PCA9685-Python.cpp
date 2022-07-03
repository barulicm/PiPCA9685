#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <PiPCA9685/PCA9685.h>

namespace py = pybind11;

using namespace PiPCA9685;

PYBIND11_MODULE(PiPCA9685, m) {
  m.doc() = "Raspberry Pi driver library for PCA9685-based servo controllers.";

  py::class_<PCA9685>(m, "PCA9685")
          .def(py::init<std::string,int>(),py::arg("device") = "/dev/i2c-1", py::arg("address") = 0x40)
          .def("set_pwm_freq", &PCA9685::set_pwm_freq)
          .def("set_pwm", &PCA9685::set_pwm)
          .def("set_all_pwm", &PCA9685::set_all_pwm)
          .def("set_pwm_ms", &PCA9685::set_pwm_ms);
}