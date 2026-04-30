#include <Wire.h>
#include <slight_FDC1004.h>

slight_FDC1004 fdc;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Starting sensor...");
  
  if (!fdc.begin()) {
    Serial.println("FDC1004 NOT detected!");
    while (1);
  }

  Serial.println("FDC1004 detected!");
}

void loop() {
  int16_t value = fdc.measurement_read(0);
  delay(500);

  Serial.print("Value: ");
  Serial.println(value);

  delay(500);
}