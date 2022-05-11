#include <Arduino.h>
#include "IRremote/IRremote.h"

/***
 * control the value of RGB to mix the color by which you can understand RGB better.
 ***/
const int irReceiverPin = 7;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

unsigned char redValue = 255;
unsigned char greenValue = 255;
unsigned char blueValue = 255;

unsigned int curChannel = 1;

const int ledPin = 13;

IRrecv irReceiver(irReceiverPin);

decode_results results;

void updateColor(int diff);

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    irReceiver.enableIRIn();
}

void loop() {
    if (irReceiver.decode(&results)) {
        Serial.print("irCode: ");
        Serial.print(results.value, HEX);
        Serial.print(", bits: ");
        Serial.println(results.bits);
        irReceiver.resume();
    }
    delay(600);
    switch (results.value) {
        case 0xFF30CF:  // press 1
            curChannel = 1;
            break;
        case 0xFF18E7: // press 2
            curChannel = 2;
            break;
        case 0xFF7A85: // press 3
            curChannel = 3;
            break;
        case 0xFFA857: // press +
            updateColor(50);
            break;
        case 0xFFE01F: // press 1
            updateColor(-50);
            break;
        case 0xFFA25D:
            digitalWrite(ledPin, HIGH);
            break;
        default:
            digitalWrite(ledPin, LOW);
    }
    results.value = 0;
}

void updateColor(int diff) {
    switch (curChannel) {
        case 1:
            redValue += diff;
            break;
        case 2:
            greenValue += diff;
            break;
        case 3:
            blueValue += diff;
            break;
        default:
            break;
    }
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
    Serial.println("current color");
    Serial.println(redValue);
    Serial.println(greenValue);
    Serial.println(blueValue);

}