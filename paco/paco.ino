#include <DHT.h>

void setup() {
  DHT.attach(9);
  Serial.begin(9600;)
  }

 void loop() {
  Serial.println((float)DHT.humidity, DEC);
  delay(1500);
  }
