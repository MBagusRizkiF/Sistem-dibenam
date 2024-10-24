int pir = 18;
int status;

void setup() {
  Serial.begin(115200);
  pinMode(pir, INPUT);
}

void loop() {
  status = digitalRead(pir);

  if (status == 1) {
    Serial.println("Terdapat Gerakan");
  } else {
    Serial.println("Tidak Terdapat Gerakan");
  }

  delay(100);
}