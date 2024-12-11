#include <LiquidCrystal.h>
//LiquidCrystal lcd (RS, EN, D4, D5, D6, D7 ); 
  LiquidCrystal lcd (2 ,  3,  4,  5,  6,  7 ); 


float lm35 = A0 ; 
int fan = 8;
int lamp = 9 ; 
void setup() {
 lcd.begin(16, 2);
 pinMode(fan, OUTPUT);
 pinMode(lamp, OUTPUT);
 pinMode(lm35, INPUT); 
}

void loop() {
    float t = analogRead(lm35);
    float temp1 = t*5/1023; 
    float temp = temp1 * 100 ; 

    lcd.setCursor(0,0); 
    lcd.print("Nhiet do: ");
    lcd.print(temp); 
    lcd.setCursor(0,1);
    lcd.print(" L01 - Nhom 11");
    if ( temp >= 30 )
        {
          digitalWrite(fan, HIGH);
          digitalWrite(lamp, LOW);
        }
    if  (temp <= 27 )
        {
          digitalWrite(lamp, HIGH);
          digitalWrite(fan, LOW);
        }
    if  ( temp < 30 && temp > 27 )
        {
          digitalWrite(lamp, LOW);
          digitalWrite(fan, LOW);
        }
    
    delay(500);
}
