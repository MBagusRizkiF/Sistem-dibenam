#include <DHT.h> 

#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT22 Test!"));
  dht.begin();
  // put your setup code here, to run once:
}

void loop() {
  delay(2000);

  float h = dht.readHumidity(); //Mambaca nilai kelembapan
  float t = dht.readTemperature(); //Suhu
  float f = dht.readTemperature(true); //Suhu (F)

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% Temperature: ");
  Serial.print(t);
  Serial.print("C ");
  Serial.print(f);
  Serial.println("F ");
}
