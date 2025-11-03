#include "DeviceController.hpp"
#include <Arduino.h>


void DeviceController::begin() {
Serial.println("DeviceController ready");
heaterOn_ = false;
lightOn_ = false;
}


void DeviceController::update(const SensorSnapshot &s) {
// Rule 1: nếu nhiệt độ < 22°C thì bật heater
if (s.temperature < 22.0f && !heaterOn_) {
heaterOn_ = true;
Serial.println("[DeviceController] Heater ON");
} else if (s.temperature >= 24.0f && heaterOn_) {
heaterOn_ = false;
Serial.println("[DeviceController] Heater OFF");
}


// Rule 2: nếu ánh sáng < 100 lux thì bật đèn
if (s.light < 100.0f && !lightOn_) {
lightOn_ = true;
Serial.println("[DeviceController] Light ON");
} else if (s.light >= 150.0f && lightOn_) {
lightOn_ = false;
Serial.println("[DeviceController] Light OFF");
}
}