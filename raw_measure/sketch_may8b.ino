#include <HX711.h>

const int HX_DT = 3;
const int HX_SCK = 2;

HX711 scale;

void setup() {
  Serial.begin(57600);

  scale.begin(HX_DT, HX_SCK);

  delay(2000);

  Serial.println("TARE...");

  scale.set_scale(1);
  scale.tare(20);

  Serial.println("EMPTY READY");
}

void loop() {

  long raw = scale.get_units(10);

  Serial.print("RAW: ");
  Serial.println(raw);

  delay(1000);
}