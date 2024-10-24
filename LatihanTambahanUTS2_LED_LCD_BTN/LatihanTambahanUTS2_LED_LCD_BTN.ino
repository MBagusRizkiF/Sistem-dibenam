/*
Buatlah rangkaian 2 LED, Button, LCD. 
LCD Dapat Menampilkan Nilai Angka Ketika Angka Pada LCD Bernilai Genap Maka LED 1 akan Menyala 
jika Angka Bernilai Ganjil Maka LED 2 akan Menyala dan Ketika Nilai nya pada LCD bernilai 10 LED 1 dan LED 2 akan Menyala.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int led1 = 25;
int led2 = 26;
int button = 33;
int pencet = 0;
int status = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.backlight();

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  status = digitalRead(button);

  if(status == 1){
    pencet++;
  }

  lcd.setCursor(0, 0);
  lcd.print(pencet);

  if(pencet == 10){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }else if(pencet % 2 == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  delay(150);
}
