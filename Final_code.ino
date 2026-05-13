#include <Wire.h>
#include <slight_FDC1004.h>

slight_FDC1004 fdc;

int pumpPin = 8;
int speakerPin = 7;

const int32_t WATER_THRESHOLD = 1900000000;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(pumpPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);

  digitalWrite(pumpPin, LOW);
  noTone(speakerPin);

  fdc.begin();

  fdc.measurement_config_chA_set(0, slight_FDC1004::config_chA_CIN1);
  fdc.measurement_config_chB_set(0, slight_FDC1004::config_chB_CAPDAC);
  fdc.measurement_config_write(0);

  fdc.measurement_init_set(0, true);
  fdc.measurement_rate_set(slight_FDC1004::repeate_rate_100Ss);
  fdc.measurement_repeate_set(true);
  fdc.fdc_config_write();

  Serial.println("RO Sentinel ready!");
}

void loop() {
  fdc.update();
  int32_t value = fdc.measurement_get(0);

  Serial.print("Raw value: ");
  Serial.println(value);

  if (value >= WATER_THRESHOLD) {
    Serial.println("WATER DETECTED - Pump ON, Alarm ON");
    digitalWrite(pumpPin, HIGH);
    tone(speakerPin, 440);
  } else {
    Serial.println("Dry - Pump OFF, Alarm OFF");
    digitalWrite(pumpPin, LOW);
    noTone(speakerPin);
  }

  delay(200);
}