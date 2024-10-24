/*
Jika jarak benda < 20cm, maka LED dan buzzer nyala 
Ukuran jarak ditampilkan di LCD
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define TRIG_PIN 4
#define ECHO_PIN 17
#define LED 14
int buz = 5;

LiquidCrystal_I2C lcd(0x27, 16, 1);

float duration, distance_cm;

void setup() {
  Serial.begin (9600);
  pinMode(TRIG_PIN, OUTPUT); //Pengirim Gelombang
  pinMode(ECHO_PIN, INPUT); //Penerima Gelombang
  pinMode(LED, OUTPUT); 
  pinMode(buz, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);//Mengrim Gelombang 
  delay(10); //Ukuran Panjng Gelombang Suara yang dikirim
  digitalWrite(TRIG_PIN, LOW); //Berhenti untuk kirim suara
  
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance_cm = 0.017 * duration;
  if(distance_cm < 20){
    digitalWrite(LED, HIGH);
    digitalWrite(buz, HIGH);
    delay(500); // biar kedap kedip
    digitalWrite(LED, LOW); // biar kedap kedip
    digitalWrite(buz, LOW); // biar kedap kedip
  }
  else {
    digitalWrite(LED, LOW);
    digitalWrite(buz, LOW);
  }
  
  lcd.print("Jarak: ");
  lcd.print(distance_cm);
  lcd.println(" cm");
  lcd.setCursor(0, 0); 
  delay(250);
  lcd.clear();
  delay(250);
}