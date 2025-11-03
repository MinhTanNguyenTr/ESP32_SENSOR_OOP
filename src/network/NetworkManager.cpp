#include "NetworkManager.hpp"
#include <Arduino.h>


#ifdef WIFI_ENABLED
#include <WiFi.h>
const char* ssid = "Ca Map";
const char* pass = "camap7979";
#endif


void NetworkManager::begin() {
#ifdef WIFI_ENABLED
Serial.printf("Connecting to WiFi %s...\n", ssid);
WiFi.begin(ssid, pass);
unsigned long start = millis();
while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
delay(200);
Serial.print('.');
}
Serial.println();
if (WiFi.status() == WL_CONNECTED) {
Serial.print("WiFi connected, IP: ");
Serial.println(WiFi.localIP());
} else {
Serial.println("WiFi connect failed (timeout)");
}
#else
Serial.println("NetworkManager: compiled without WIFI_ENABLED");
#endif
}


void NetworkManager::handle() {
// Tại đây có thể mở server HTTP trả snapshot
}