int pot = 33;

void setup() {
  // put your setup code here, to run
  Serial.begin(9600);
}

void loop() {
  int potv = analogRead(pot);
  Serial.println(potv);
  delay(500);
}

//Ke arah VCC makin kecil
//Ke arah GND makin besar