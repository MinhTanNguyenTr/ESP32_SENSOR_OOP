#include <Arduino.h>
#include "sensor/SensorManager.hpp"
#include "network/NetworkManager.hpp"
#include "logger/DataLogger.hpp"
#include "controller/DeviceController.hpp"


SensorManager sensorManager;
NetworkManager networkManager;
DataLogger dataLogger;
DeviceController deviceController;


unsigned long lastTick = 0;
const unsigned long TICK_MS = 1000; // 1s


void setup() {
Serial.begin(115200);
delay(500);
Serial.println("ESP32 OOP project starting...");


sensorManager.begin();
dataLogger.begin();
deviceController.begin();


#ifdef WIFI_ENABLED
networkManager.begin();
#else
Serial.println("WIFI disabled in build (WIFI_ENABLED not defined)");
#endif
}


void loop() {
unsigned long now = millis();
if (now - lastTick >= TICK_MS) {
lastTick = now;


// Cập nhật cảm biến (giả lập)
sensorManager.update();
auto snapshot = sensorManager.getSnapshot();


// Ghi log
dataLogger.logSnapshot(snapshot);


// Ra quyết định
deviceController.update(snapshot);


#ifdef WIFI_ENABLED
networkManager.handle();
#endif
}


// cho CPU nghỉ
delay(10);
}