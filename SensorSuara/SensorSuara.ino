#define SENSOR_PIN 18

int lastState = HIGH;
int currentState;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == HIGH && currentState == LOW)
    Serial.println("The Sound has been detected");
  else if (lastState == LOW && currentState == HIGH)
    Serial.println("The sound has disappeard");
  
  lastState = currentState;
  delay(100);
}
