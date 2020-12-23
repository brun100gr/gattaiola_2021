#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32
                    // Has to be done before including "OTA.h"

#include "OTA.h"
#include "telegramBot.h"
#include "credentials.h"
#include "sendMail.h"

uint32_t entry;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  setupOTA("gattaiola", mySSID, myPASSWORD);
  setupTelegramBot(mySSID, myPASSWORD);
}
bool sendOnce = true;
void loop() {
  entry = micros();
  ArduinoOTA.handle();
  telegramLoop();
  if (sendOnce == true) {
    sendMail(123);
    sendOnce = false;
  }
  delay(1000);
  // Your code here
}
