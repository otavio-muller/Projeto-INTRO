/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>
#include <Wire.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int ledVermelho = 5;
int ledVerde = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Wire.begin();    
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Ocupacao");

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledVerde, LOW);
}

void loop() {
  lcd.setCursor(0, 1);
  Wire.requestFrom(2, 1);   

  while (Wire.available()) { 
    int c = Wire.read(); 
    if(c == 0){
      lcd.print("minima");
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
    }
    else if(c == 1 || c == 2){
      lcd.print("media ");
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
      delay(7000);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledVerde, HIGH);
      delay(7000);
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
    }
    else{
      lcd.print("maxima");
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
      delay(3000);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledVerde, HIGH);
      delay(10000);
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledVerde, LOW);
    };
  }

  delay(500);
}

