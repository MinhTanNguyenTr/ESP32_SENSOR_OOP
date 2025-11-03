#pragma once
#include <stdint.h>
#include <array>


struct SensorSnapshot {
float temperature; // °C
float humidity; // %
float light; // lux (giả lập)
float pressure; // hPa
};


class SensorManager {
public:
SensorManager();
void begin();
void update();
SensorSnapshot getSnapshot() const;


private:
SensorSnapshot snapshot_;
unsigned long startMillis_;
float pseudoNoise();
};