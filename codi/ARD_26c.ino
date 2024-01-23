/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD026
 * Data: 19/01/2022
 * Descripcio: Lectura de sensor de contacte
 * i presentacio en LCD
 * Nota:
 * 
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Crea l'objecte lcd amb direcció 0x27, 16 caracters y 2 línees

int led=13;
int DOsensorpin=3;
int AOsensorpin=A0;
int DOsensorValor=0;
int AOsensorValor=0;

void setup() 
{
  pinMode(led,OUTPUT);
  pinMode(DOsensorpin, INPUT);
  Wire.begin();
  lcd.begin();
  lcd.backlight();
  Intro();
  Serial.begin(9600);
  
}

void loop()
{
  delay(2000);
  DOsensorValor=digitalRead(DOsensorpin);
  if (DOsensorValor==HIGH)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  AOsensorValor=analogRead(AOsensorpin);
  lcd.setCursor(0,0);
  lcd.print("Sensor tactil:");
  lcd.setCursor(0,1);
  lcd.print(AOsensorValor);
  Serial.println(AOsensorValor);
  
}

void Intro()
{
  lcd.setCursor(0,0);
  lcd.print("CartroTECH");
  delay(2000);
}
