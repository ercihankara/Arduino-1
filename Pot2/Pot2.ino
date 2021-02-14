int analogPin = 14; // A0
int value = 0;
int digitalPin = 4;


void setup() {
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(analogPin);
  Serial.println(value);
  int mapped = map(value, 0, 1023, 0, 10);
  digitalWrite(digitalPin, HIGH);
  delay(mapped);
  digitalWrite(digitalPin, LOW);
  delay(10 - mapped);
}
