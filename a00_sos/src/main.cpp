#include <Arduino.h>

int ledPin = 7;
int charSpace = 200;
int wordSpace = 400;
int ditLen = 200;
int dashLen = 500;

void setup()
{
  pinMode(13, OUTPUT);
}

void sosV1()
{
  // output S
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);

  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);

  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(400);

  // output O
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(200);

  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(200);

  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(400);

  // output S
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);

  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);

  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(400);
}

void sosV2()
{
  // output S
  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);

  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);

  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(wordSpace);

  // output O
  digitalWrite(ledPin, HIGH);
  delay(dashLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);

  digitalWrite(ledPin, HIGH);
  delay(dashLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);

  digitalWrite(ledPin, HIGH);
  delay(dashLen);
  digitalWrite(ledPin, LOW);
  delay(wordSpace);

  // output S
  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);

  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);

  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(wordSpace);
}

void writeDot()
{
  digitalWrite(ledPin, HIGH);
  delay(ditLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);
}

void writeDash()
{
  digitalWrite(ledPin, HIGH);
  delay(dashLen);
  digitalWrite(ledPin, LOW);
  delay(charSpace);
}

void sosV3()
{
  // 如果想优化是不是可以配置一个字符到摩斯码的映射关系，来快速生成。进一步是否能让不同硬件通过摩斯码来通信。
  // output S ...
  writeDot();
  writeDot();
  writeDot();
  delay(charSpace);

  // output O
  writeDash();
  writeDash();
  writeDash();
  delay(charSpace);

  // output S
  writeDot();
  writeDot();
  writeDot();
  delay(charSpace);
}

void loop()
{
  // sosV1();
  // sosV2();
  sosV3();
  delay(1000);
}
