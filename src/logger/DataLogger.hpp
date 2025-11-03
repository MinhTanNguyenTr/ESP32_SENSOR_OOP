
#include "sensor/SensorManager.hpp"


class DataLogger {
public:
void begin();
void logSnapshot(const SensorSnapshot &s);
};