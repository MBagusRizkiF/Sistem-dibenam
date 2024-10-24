int pin_DO = 18;
int pin_AO = 4;

void setup() {
  pinMode(pin_DO, INPUT);
  Serial.begin(9600);
}

void loop() {
  int statusDigital = digitalRead(pin_DO);
  int statusAnalog = analogRead(pin_AO);

  Serial.print("Digital Output: ");
  Serial.println(statusDigital);

  Serial.print("Analog Output: ");
  Serial.println(statusAnalog);

  delay(1000);
}
