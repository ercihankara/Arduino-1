int pin = 4;


void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
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
        Serial.println(i);
     }
     else{
        digitalWrite(pin,HIGH);
        delay(2000);
     }    
    }  
}
