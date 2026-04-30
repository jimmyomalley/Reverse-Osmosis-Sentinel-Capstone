int pumpPin = 8;

void setup() {
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  digitalWrite(pumpPin, HIGH);
  delay(3000);

  digitalWrite(pumpPin, LOW);
  delay(3000);
}