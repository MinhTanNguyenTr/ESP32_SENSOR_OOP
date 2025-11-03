#include "SensorManager.hpp"
#include <Arduino.h>


SensorManager::SensorManager() {
snapshot_ = {25.0f, 50.0f, 200.0f, 1013.25f};
startMillis_ = 0;
}


void SensorManager::begin() {
startMillis_ = millis();
}


static float sineWave(float t, float period, float minv, float maxv) {
float phase = (t / period) * 2.0f * PI;
float s = (sin(phase) + 1.0f) / 2.0f; // 0..1
return minv + s * (maxv - minv);
}


float SensorManager::pseudoNoise() {
// small pseudo-random variation
return (float)(random(-50, 50)) / 100.0f; // -0.5 .. 0.49
}


void SensorManager::update() {
unsigned long t = millis() - startMillis_;


// Temperature: slow daily swing 20..30
snapshot_.temperature = sineWave(t, 60UL * 1000UL * 5UL, 20.0f, 30.0f) + pseudoNoise();
// Humidity: inverse-ish
snapshot_.humidity = 40.0f + (30.0f - (snapshot_.temperature - 20.0f)) + pseudoNoise();
// Light: faster variation 0..1000
snapshot_.light = sineWave(t, 10000UL, 0.0f, 1000.0f) + pseudoNoise() * 10.0f;
// Pressure: small variations around 1013
snapshot_.pressure = 1012.0f + sineWave(t, 60000UL, -1.5f, 1.5f);
}


SensorSnapshot SensorManager::getSnapshot() const {
return snapshot_;
}