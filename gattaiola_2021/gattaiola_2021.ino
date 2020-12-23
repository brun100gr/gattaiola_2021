#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32
                    // Has to be done before including "OTA.h"

#include "OTA.h"
#include "telegramBot.h"
#include "credentials.h"

uint32_t entry;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  setupOTA("gattaiola", mySSID, myPASSWORD);
  setupTelegramBot(mySSID, myPASSWORD);
}

void loop() {
  entry = micros();
  ArduinoOTA.handle();
  telegramLoop();
  delay(1000);
  // Your code here
}
