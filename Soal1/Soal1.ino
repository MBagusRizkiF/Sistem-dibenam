int led1 = 4;
int led2 = 14;
int buz1 = 23;
int buz2 = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (buz1, OUTPUT);
  pinMode (buz2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (led1, HIGH);
  digitalWrite (led2, LOW);
  digitalWrite(buz1, HIGH);
  digitalWrite(buz2, LOW);
  delay(3500);

  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(buz1, LOW);
  digitalWrite(buz2, HIGH);
  delay(3500);

}
