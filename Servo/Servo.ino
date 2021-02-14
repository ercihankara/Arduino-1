#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int val = analogRead(A0);

  if(val = 0){
    for (pos = 0; pos <= 180; pos++){
      myservo.write(pos); // "myservo" depends on the name I declared
      delay(30);     
    }
  }
  if(val =! 0){
    for (pos = 180; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(30);                       
    }
  }
}
