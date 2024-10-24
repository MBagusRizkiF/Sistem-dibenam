#define TRIG_PIN 4
#define ECHO_PIN 17

float duration, distance_cm;

void setup() {
  Serial.begin (9600);
  pinMode(TRIG_PIN, OUTPUT); //Pengirim Gelombang
  pinMode(ECHO_PIN, INPUT); //Penerima Gelombang 
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);//Mengrim Gelombang 
  delay(10); //Ukuran Panjng Gelombang Suara yang dikirim
  digitalWrite(TRIG_PIN, LOW); //Berhenti untuk kirim suara
  
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance_cm = 0.017 * duration;

  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  
  delay(500);
}