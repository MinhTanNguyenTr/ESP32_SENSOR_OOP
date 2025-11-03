#pragma once
#include "SensorManager.h"


class DataLogger {
public:
void begin();
void logSnapshot(const SensorSnapshot &s);
};