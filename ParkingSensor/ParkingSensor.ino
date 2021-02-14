#include <Servo.h>
// servo was addition, so didn't fit too much
Servo myservo;
int pos = 0;

const int buzzer = 11;
const int led[] = {4, 5, 6, 7};// 4-->redleft; 7-->redright;5-->green;6-->yellow
const int trigPin = 9;
const int echoPin = 10;

long duration; // microseconds
float distance;
int closeness;

void setup() {

  myservo.attach(12);  // attaches the servo on pin 12 to the servo object
  myservo.write(0);  
  
  pinMode(buzzer, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
  }

void loop() {
  
   //close first
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

  closeness = map(distance, 0, 50, 1, 4); // when max distance decreased, grouping to 1-4 interval decreases
  Serial.println(closeness);
  
  for(int i=0; i < 4; i++){
    digitalWrite(led[i], LOW);
    }
    
  /*for(int i=0; i < closeness; i++){
    digitalWrite(led[i], HIGH);
    }*/

   if (closeness == 1){
      myservo.attach(12);
      digitalWrite(led[0], HIGH);
      for (pos = 0; pos <= 45; pos++){
        myservo.write(pos); // "myservo" depends on the name I declared
        delay(45);
        if(pos == 45)
          myservo.detach();
      }  
   }

   else if (closeness == 2){
      myservo.attach(12);
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], HIGH);
      for (pos = 45; pos <= 90; pos++){
          myservo.write(pos); // "myservo" depends on the name I declared
          delay(45);
          if(pos == 90)
            myservo.detach();
      }  
    }
   else if (closeness == 3){
      myservo.attach(12);
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], HIGH);
      digitalWrite(led[2], HIGH);
      for (pos = 90; pos <= 135; pos++){
          myservo.write(pos); // "myservo" depends on the name I declared
          delay(45);
          if(pos == 135)
            myservo.detach();
      }  
    }
   else {
      myservo.attach(12);
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], HIGH);
      digitalWrite(led[2], HIGH);
      digitalWrite(led[3], HIGH);
      for (pos = 135; pos <= 180; pos++){
          myservo.write(pos); // "myservo" depends on the name I declared
          delay(45);
          if(pos == 180)
            myservo.detach();
      }  
    }

    tone(buzzer, 100); // Send 1KHz sound signal...
    delay(100*closeness);        // ...delaying wrt to distance
    noTone(buzzer);     // Stop sound...
    delay(100*closeness);        // ...delaying wrt to distance

}
