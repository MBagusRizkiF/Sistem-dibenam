int led1 = 4;
int led2 = 22;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  for(int i = 0; i < 10; i++){
    digitalWrite (led1, HIGH);
    delay(500);
    digitalWrite (led1, LOW);
    delay(500);

    Serial.print("Lampu 1 telah berkedip: ");
    Serial.println(i + 1);
  }
  digitalWrite(led1, LOW);

  while(1) {
    digitalWrite(led2, HIGH);
  }
}