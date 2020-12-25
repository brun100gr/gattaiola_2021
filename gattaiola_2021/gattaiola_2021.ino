#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32
                    // Has to be done before including "OTA.h"

#include "OTA.h"
#include "telegramBot.h"
#include "credentials.h"
#include "sendMail.h"

uint32_t entry;

// Battery voltage is connected to GPIO 33 (Analog ADC1_CH5) 
const int batteryVoltagePin = 33;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  setupOTA("gattaiola", mySSID, myPASSWORD);
  setupTelegramBot();
}

int potValue = 0;
bool sendOnce = true;
void loop() {
  entry = micros();
  ArduinoOTA.handle();
  potValue = analogRead(batteryVoltagePin);
  if (sendOnce == true) {
    sendMail(potValue);
    sendOnce = false;
  }
  sendTelegramMessage(potValue);
  TelnetStream.println("Battery: "); TelnetStream.println(batteryVoltagePin);  TelnetStream.println("");
  delay(10000);
  // Your code here
}
