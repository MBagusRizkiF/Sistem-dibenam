#include <ESP32Servo.h>

int servoPin = 22;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(servoPin);
  servo1.write(0);
}

void loop() {
// put your main code here, to run repeatedly:
for(int i = 0; i <= 180; i++) {
  servo1.write(i);
  Serial.println(i);
  delay(20);
}

for(int i = 180; i >= 0; i--) {
  servo1.write(i);
  Serial.println(i);
  delay(5);
}
}