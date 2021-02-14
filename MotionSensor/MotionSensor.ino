void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
    boolean motion;
    motion = digitalRead(7);
    delay(3000);
    Serial.println(motion);
}
