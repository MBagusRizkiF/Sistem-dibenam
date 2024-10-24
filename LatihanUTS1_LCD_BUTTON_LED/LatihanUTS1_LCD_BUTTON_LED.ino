#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 1);

int Lampu1 = 5;
int Lampu2 = 17;
int button = 25;
int buttonState = 0;
int lastButtonState = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int buttonPressCount = 0;

void setup() {
  pinMode (Lampu1, OUTPUT);
  pinMode (Lampu2, OUTPUT);
  pinMode (button, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.clear();
  digitalWrite(Lampu1, HIGH);
  digitalWrite(Lampu2, HIGH);
}

void loop() {
  int reading = digitalRead(button);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        buttonPressCount++;
        if (buttonPressCount % 5 == 0) {
          digitalWrite(Lampu1, LOW);
          digitalWrite(Lampu2, LOW);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Alip Ganteng");
        } else if (buttonPressCount % 2 == 0) {
          digitalWrite(Lampu1, HIGH);
          digitalWrite(Lampu2, HIGH);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Genap");
        } else {
          digitalWrite(Lampu1, HIGH);
          digitalWrite(Lampu2, LOW);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Ganjil");
        }
      }
    }
  }

  lastButtonState = reading;
}
