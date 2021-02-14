int pin = 4;
int anal = 14; // A0

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(anal, INPUT);
}

void loop() {
  
  /*digitalWrite(pin,HIGH);
  delay(5000);
  digitalWrite(pin,LOW);
  delay(5000);*/

  for (int i=0; i<50; i++){
     if (i%2==0){
        digitalWrite(pin,LOW);
        delay(2000);
        //Serial.println(i);
     }
     else{
        digitalWrite(pin,HIGH);
        delay(2000);
     }    
    }

      int value = analogRead(anal);
      Serial.println(value); // or print("\n");
      delay(500);

      float final_val = map(value, 0, 1023, 0, 5); // made the ratio of 0-1023 directly voltage read!!!
      // int to float mapping fails, but float to float is valid!!!
      Serial.println(final_val);     
      
}
