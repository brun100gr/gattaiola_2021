/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/telegram-esp32-motion-detection-arduino/
  
  Project created using Brian Lough's Universal Telegram Bot Library: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
*/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <MapFloat.h>
#include "credentials.h"

// Initialize Telegram BOT
#define BOTtoken "1424090199:AAGjbW1gEBmCfZ8nn7hbGzMHflGBJ9NBIbc"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "1007315026"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setupTelegramBot() {
  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void sendTelegramMessage(int value) {
    float batteryVoltage = mapFloat(value, 0.0f, 4095.0f, 0.0f, 4.2f);
    float batteryLevel = mapFloat(value, 0.0f, 4095.0f, 0.0f, 100.0f);
    bot.sendMessage(CHAT_ID, "Battery voltage(" + String(value) + "): " + String(batteryVoltage) + "V - " + String(batteryLevel) + "%", "");
    TelnetStream.println("Battery voltage(" + String(value) + "): " + String(batteryVoltage) + "V - " + String(batteryLevel) + "%");
    Serial.println("Motion Detected");
    delay(1000);
}
