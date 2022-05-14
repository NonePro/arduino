/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-14
 * 
 * @functional: 
 * 双色LED灯学习
 * 
 * @connection:
 * Dual-color LED   Arduino R3
 * R                    11
 * GND                  GND 
 * G                    10 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>

int redPin = 11;
int greenPin = 10;

/**
 * @brief 
 * 双色LED模块共阴极。
 * 1、如果R和G同时打开会怎样？
 *  -> 如果先点亮的是红色，则最终显示为红色。如果先点亮的为绿色，最终表现为绿色。
 * 2、如果使用的是并联电路呢？
 * 
 */
void demoWriteAtTheSameTime(){
  Serial.println("demo1 (write at the same time) start");
  Serial.println("--- turn on at he same time");
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,HIGH);
  delay(1000);
  Serial.println("--- turn off the red first");
  digitalWrite(redPin,LOW);
  delay(1000);
  Serial.println("--- turn off the green then");
  digitalWrite(greenPin,LOW);
  Serial.println("demo1 (write at the same time) end");
}

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  demoWriteAtTheSameTime();
  delay(5000);
}