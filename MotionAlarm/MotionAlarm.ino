//#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int buzzer = 8;
const int led = 6;
const int sensor = 7;
//const int out = 5;
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal_I2C lcd(0x20, 16, 2);


void setup() {
  pinMode(sensor, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
//pinMode(out, OUTPUT);
  lcd.begin();          // Initiate the LCD module
  lcd.backlight();     // Turn on the backlight
  Serial.begin(9600);
  }

void loop() {

  bool motion;
//digitalWrite(out, HIGH);
  motion = digitalRead(sensor);
  delay(200);
  Serial.println(motion);

  if(motion == HIGH){
    lcd.setCursor(0, 0);
    lcd.print("Get the F out!!!");
    digitalWrite(led, HIGH);
    delay(1);
    tone(buzzer, 1000);
    delay(2000);
    digitalWrite(led, LOW);
    delay(1);
    noTone(buzzer);
    delay(2000);
    
  }
  
  else{
    noTone(buzzer);
    digitalWrite(led, LOW);
    lcd.home();
    lcd.print("Get the F out!!!");
    }

}
