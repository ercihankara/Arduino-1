//int buzzer = 9;
int red = 6;
int green = 3;
int yellow = 5;
const int LdrLeft = A0;
const int LdrRight = A5;
//bool buzzerFlag = true;

void setup() {
  Serial.begin(9600);
  //pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(LdrLeft, INPUT);
  pinMode(LdrRight, INPUT);
}

void loop() {
  int StatusLeft = analogRead(LdrLeft);
  int StatusRight = analogRead(LdrRight);
 
  if (StatusLeft <= 200 && StatusRight <= 200) {
    
    //buzzerFlag = false;
    //tone(buzzer, 20, 600); // tone(pin, frequency, duration)
    //delay(150);
 
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    Serial.print("Its DARK, Turn on the Red and Green and Yellow: \n");
    Serial.println(StatusLeft);
    Serial.println(StatusRight);

  } 

  else if (StatusLeft > 200 && StatusRight <= 200){
    
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);   
    Serial.print("Red is down and yellow is on : \n");
    
    }
    
  else if (StatusLeft > 200 && StatusRight > 200){

    //buzzerFlag = false;
    //tone(buzzer, 20, 600);
    //delay(150);
    
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);  
    Serial.println("Its BRIGHT, Turn off the all the leds: \n");
    Serial.println(StatusLeft);
    Serial.println(StatusRight);
    
    }

   else{
    
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);   
    Serial.println("Red is on and yellow is down: \n");
    
    }
}
