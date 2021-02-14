int pin_num = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pin_num, OUTPUT);
  }

void loop() {
  int value = analogRead(A0);
  Serial.println(value); // 566
  delay(100);
  if (value < 600){
    digitalWrite(pin_num, HIGH);
    delay(100);
    }
  else{
    digitalWrite(pin_num, LOW);
    delay(100);
    }
}
