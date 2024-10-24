/*
Buatlah rangkaian DHT, LCD dan LED. 
LCD dapat Menampilkan Kelembaban pada baris ke 1 yang nilai nya didapat dari sensor DHT, 
dan pada baris kedua Menampilkan suhu DHT dalam format celcius, 
dan pada saat suhu nya sangat tinggi maka LED akan menyala.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 14
#define LED 25
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHT22 test!"));
  dht.begin();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.backlight();
  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  // Menampilkan Nilai Kelembapan di baris 1
  lcd.setCursor(0, 0);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print("%");
  // Menampilkan suhu DHT dalam Celcius di baris 2
  lcd.setCursor(0, 1);
  lcd.print("Suhu: ");
  lcd.print(t);
  lcd.print("C");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(t);
  Serial.print("C ");

  if(t >= 32){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW); 
  }
}
