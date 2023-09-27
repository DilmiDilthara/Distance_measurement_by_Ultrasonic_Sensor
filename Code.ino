#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int echo= 4;
int Trig=3;
int buzzer=A0;
long duration, inches, cm, distance;


void setup() {
  Serial.begin(9600);
  pinMode(echo, OUTPUT);
  pinMode(Trig, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16,2);
  lcd.clear();
  
}

void loop() {

  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(Trig, LOW);
  duration = pulseIn(echo, HIGH);

  distance = ((duration*0.034)/2);

  lcd.clear();
  lcd.print("Distance (cm) : ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.setCursor(1,1);

  if(distance < 50){

    digitalWrite(buzzer, HIGH);  
    }

    else{
      digitalWrite(buzzer, LOW);
      }

     delay(100);

}
