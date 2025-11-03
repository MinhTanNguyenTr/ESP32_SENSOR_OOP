#include "DataLogger.hpp"
#include <Arduino.h>


void DataLogger::begin() {
Serial.println("DataLogger initialized");
}


void DataLogger::logSnapshot(const SensorSnapshot &s) {
// Simple Serial CSV style
Serial.printf("%lu, T=%.2fC, H=%.2f%%, L=%.1flux, P=%.2fhPa\n",
millis(), s.temperature, s.humidity, s.light, s.pressure);
}