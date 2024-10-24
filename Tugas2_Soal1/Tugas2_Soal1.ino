/*
Gunakan sensor DHT untuk membaca suhu dan kelembapan, dan
tampilkan hasilnya ke LCD menggunakan button dengan kondisi:
Jika button ditekan sekali, LCD akan menampilkan kelembapan
Jika button ditekan kedua kali, LCD akan menampilkan suhu
dalam celcius
Jika Button ditekan ketiga kali, LCD akan menampilkan suhu
dalam fahrenheit
*/

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Konfigurasi DHT
#define DHTPIN 13      // Pin data dari sensor DHT
#define DHTTYPE DHT22 // Atau DHT22, sesuaikan dengan jenis sensor

DHT dht(DHTPIN, DHTTYPE);

// Konfigurasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C LCD bisa bervariasi, sesuaikan jika perlu

// Konfigurasi Button
#define BUTTON_PIN 33 // Pin tombol
int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// Variabel untuk menyimpan kondisi tampilan
int displayMode = 0;

void setup() {
  // Inisialisasi sensor DHT
  dht.begin();
  
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  
  // Inisialisasi tombol
  pinMode(BUTTON_PIN, INPUT);
  
  // Tampilan awal di LCD
  lcd.setCursor(0, 0);
  lcd.print("Press button");
}

void loop() {
  // Debouncing tombol
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      // Jika tombol ditekan
      if (buttonState == HIGH) {
        displayMode = (displayMode + 1) % 3; // Mode display berubah: 0, 1, 2
        tampilkanData(displayMode);
      }
    }
  }
  
  lastButtonState = reading;
}

void tampilkanData(int mode) {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  lcd.clear();

  if (mode == 0) {
    // Tampilkan kelembapan
    lcd.setCursor(0, 0);
    lcd.print("Suhu:");
    lcd.setCursor(0, 1);
    lcd.print(tempF);
    lcd.print(" F");
    
  } else if (mode == 1) {
    // Tampilkan suhu dalam Celsius
    lcd.setCursor(0, 0);
    lcd.print("Kelembapan:");
    lcd.setCursor(0, 1);
    lcd.print(humidity);
    lcd.print(" %");
  } else if (mode == 2) {
    // Tampilkan suhu dalam Fahrenheit
    

     lcd.setCursor(0, 0);
    lcd.print("Suhu:");
    lcd.setCursor(0, 1);
    lcd.print(tempC);
    lcd.print(" C");
  }
}