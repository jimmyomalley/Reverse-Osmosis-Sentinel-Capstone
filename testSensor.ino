#include <Wire.h>
#include <slight_FDC1004.h>

slight_FDC1004 fdc;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Serial.println("Starting...");

  fdc.begin();

  // Configure measurement 1: CIN1 vs CAPDAC
  fdc.measurement_config_chA_set(0, slight_FDC1004::config_chA_CIN1);
  fdc.measurement_config_chB_set(0, slight_FDC1004::config_chB_CAPDAC);
  fdc.measurement_config_write(0);

  // Enable measurement 1, set rate, enable repeat
  fdc.measurement_init_set(0, true);
  fdc.measurement_rate_set(slight_FDC1004::repeate_rate_100Ss);
  fdc.measurement_repeate_set(true);
  fdc.fdc_config_write();

  Serial.println("Sensor configured!");
}

void loop() {
  fdc.update();
  int32_t value = fdc.measurement_get(0);
  Serial.print("Raw value: ");
  Serial.println(value);
  delay(200);
}