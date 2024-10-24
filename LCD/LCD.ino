#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Ukuran baris (16) dan kolom (2) LCD
int counter = 11;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}


void loop() {
  counter--;
  lcd.print(counter);
  delay(1000);
  lcd.clear();
  if (counter == 0){
      lcd.clear();
  }
}