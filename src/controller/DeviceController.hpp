#include "sensor/SensorManager.hpp"


class DeviceController {
public:
void begin();
void update(const SensorSnapshot &s);


private:
bool heaterOn_ = false;
bool lightOn_ = false;
};