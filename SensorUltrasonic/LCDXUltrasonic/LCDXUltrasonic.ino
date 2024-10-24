#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define TRIG_PIN 4
#define ECHO_PIN 17

LiquidCrystal_I2C lcd(0x27, 16, 1);

float duration, distance_cm;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); //Pengirim Gelombang
  pinMode(ECHO_PIN, INPUT); //Penerima Gelombang
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
  lcd.print("jarak: ");
  lcd.print(distance_cm);
  lcd.print("cm");
  lcd.setCursor(0, 0); 
  
  delay(250);
  lcd.clear();
  delay(250);
}