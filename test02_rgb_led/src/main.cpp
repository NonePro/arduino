/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  学习发光三原色基本知识
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Arduino.h>


const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void color(unsigned char red, unsigned char green, unsigned char blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  // basic colors
  color(0, 0, 0); // 黑色 black
  delay(1000);
  color(255, 0, 0); // 红色 red
  delay(1000);
  color(0, 255, 0); // 绿色  green
  delay(1000);
  color(0, 0, 255); // 蓝色  blue
  delay(1000);
  color(0, 255, 255); // 青色 cyan
  delay(1000);
  color(255, 0, 255); // 紫色 purple
  delay(1000);
  color(255, 255, 0); // 黄色 yellow
  delay(1000);
  color(255, 255, 255); // 白色 white
  delay(1000);

  // blend colors
  for (int i = 0; i < 30; i++)
  {
    color(rand() % 255, rand() % 255, rand() % 255);
    delay(300);
  }
}