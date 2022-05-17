#include <Arduino.h>

int readPin = A3;
int delayTime = 500;
int v2 = 0;

void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int readVal = analogRead(readPin);
  v2 = readVal * 5.0 / 1023.0;
  Serial.print(readVal);
  Serial.print("   ");
  Serial.println(v2);
  delay(delayTime);
}