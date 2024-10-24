/*
Jika nilai potensiometer > 300 BUZZER nyala, LED mati
Jika nilai Potensiometer < 300 BUZZER mati, LED nyala
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pot = 33;
const int button = 25;
int potValue = 0;
bool lastButtonState = HIGH; // Status button sebelumnya (default HIGH karena pull-up)
bool buttonPressed = false; // Menyimpan apakah button telah ditekan
int buz = 5;
int led = 27;

void setup() {
  pinMode (button, INPUT);
  pinMode (buz, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(buz, LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); //kolomxbaris
  lcd.print("Nilai terakhir: ");
  lcd.setCursor(0, 1);
  lcd.print(potValue);
}

void loop() {
  bool currentButtonState = digitalRead(button);  // Membaca status button saat ini
  
  // Hanya mendeteksi ketika button ditekan (transisi dari HIGH ke LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    buttonPressed = true;  // Button telah ditekan
  }

  // Jika buttonPressed true, baca nilai potensiometer dan tampilkan
  if (buttonPressed) {
    potValue = analogRead(pot);  // Membaca nilai potensiometer
    potValue = map(potValue, 0, 1023, 0, 100);  // Mengubah rentang nilai menjadi 0-100
    lcd.clear();  // Menghapus layar
    lcd.setCursor(0, 0);
    lcd.print("Nilai Terakhir:");
    lcd.setCursor(0, 1);
    lcd.print(potValue);  // Menampilkan nilai terbaru
    buttonPressed = false;  // Reset flag setelah nilai diperbarui

  if(potValue > 300){
    digitalWrite(buz, HIGH);
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(buz, LOW);
    digitalWrite(led, HIGH);
  }


  }

  lastButtonState = currentButtonState;  // Simpan status button sebelumnya
}
