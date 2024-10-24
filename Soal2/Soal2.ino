 int led = 15;
int buz = 16;
int button = 4;
int buttonState = 0;
int lastButtonState = 0;
int counter = 0;

void setup() {
  pinMode (led, OUTPUT);
  pinMode (buz, OUTPUT);
  pinMode (button, INPUT);
}

void loop() {
  buttonState = digitalRead (button);

  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      counter++;
      if (counter > 3) {
        counter = 0;
      }
      switch (counter) {
        case 0:
        digitalWrite(led, LOW);
        digitalWrite(buz, LOW);
        break;

        case 1:
        digitalWrite(led, HIGH);
        digitalWrite(buz, LOW);
        break;

        case 2:
        digitalWrite(led, LOW);
        digitalWrite(buz, HIGH);
        break;

        case 3:
        digitalWrite(led, HIGH);
        digitalWrite(buz, HIGH);
        break;
      }
    }
    delay(50);
  }
  lastButtonState = buttonState;
}
