
const int trigPin = 9;
const int echoPin = 10;

long duration; // microseconds
float distance;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
}

void loop() {
  // Need to clear the trigpin!!!
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);
}
