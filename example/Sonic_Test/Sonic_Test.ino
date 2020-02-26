#include <Sonic.h>

Sonic sonic(7,8);

void setup() {
  Serial.begin(9600);
  sonic.setTimeout(22000UL);
}

void loop() {
  Serial.print("Distance in CM: ");
  Serial.println(sonic.read());
  delay(1000);
}