#include <ESP32Servo.h>

#define PIN_POTENTIOMETER 27
#define PIN_SERVO 22

Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(PIN_SERVO);
}

void loop() {
  int analogValue = analogRead(PIN_POTENTIOMETER);
  
  int angle = map(analogValue, 0, 4095, 0, 180);
  
  servo1.write(angle);
  
  Serial.print("Analog value: ");
  Serial.print(analogValue);
  Serial.print(" => Angle: ");
  Serial.println(angle);
  delay(100);
}