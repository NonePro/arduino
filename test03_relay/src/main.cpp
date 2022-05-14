/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 中继器实验，通过通电产生磁场，吸合开关 
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Arduino.h>

const int relayPin = 7;

void setup() {
  pinMode(relayPin,OUTPUT);
}

void loop() {
  digitalWrite(relayPin,HIGH);
  delay(2000);
  digitalWrite(relayPin,LOW);
  delay(2000);
}