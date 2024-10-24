int pin_DO = 14;
int buz = 5;
int led = 25;

void setup() {
  pinMode(pin_DO, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int statusDigital = digitalRead(pin_DO);
  if(statusDigital == 0) {
    digitalWrite(led, HIGH);
    digitalWrite(buz, LOW);
    delay(500);

    digitalWrite(led, LOW);
    digitalWrite(buz, HIGH);
    delay(500);

  } else {
    digitalWrite(led, LOW);
    digitalWrite(buz, LOW);
  }

  Serial.print("Digital Output: ");
  Serial.println(statusDigital);

  delay(1000);
}
