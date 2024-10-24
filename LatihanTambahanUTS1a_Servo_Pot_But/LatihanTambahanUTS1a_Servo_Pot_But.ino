/* 
Buatlah rangkaian Servo, Button, dan Potensiometer. 
Button dipencet counter nambah 1, jika counter ganjil servo searah potensiometer, 
jika genap servo berlawanan arah.
*/

#include<ESP32Servo.h>

#define PIN_POTENTIOMETER 14
#define PIN_SERVO 15

int button = 25;
int counter = 1;
int status;
int angle;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  servo1.attach(PIN_SERVO);
}



void loop() {
  int analogValue = analogRead(PIN_POTENTIOMETER);
  status = digitalRead(button);

  if(status == 1) {
    counter++;
    Serial.println(counter);
  }

  if(counter > 3) {
    counter = 1;  // Reset counter jika lebih dari 3
  }

  delay(150);  // Debounce untuk tombol


  // put your main code here, to run repeatedly:
  // Bikin Fungsi Button
  if (counter == 1) {
    angle = map(analogValue, 0,  4095, 0,  180);
    servo1.write(angle);
    Serial.println("Ganjil");
  } else if (counter == 2) {
    angle = map(analogValue, 0,  4095, 180,  0);
    servo1.write(angle);
    Serial.println("Genap");
  } else {
    Serial.println("Pengkodisian Sudah Selesai");
  }
}

