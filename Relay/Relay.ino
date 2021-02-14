void setup() {
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(7, HIGH);
  delay(2500); //2.5 s = 2500 ms
  digitalWrite(7, LOW);
  delay(5000);
}
