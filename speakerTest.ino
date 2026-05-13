// Simple tone example
int speakerPin = 7;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  tone(speakerPin, 440);   // Play 440 Hz (A note)
  delay(500);
  noTone(speakerPin);      // Silence
  delay(500);
}