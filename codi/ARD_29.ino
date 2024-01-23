/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD029
 * Data: 26/01/2022
 * Descripcio: Funcionament del modul seguidor de linia
 * Nota:
 * 
 */
 
int Led = 13;     
int buttonpin = 3; 
int  val;
void  setup()
{
  pinMode(Led, OUTPUT); 
  pinMode(buttonpin, INPUT); 
  Serial.begin(9600);
}
void  loop()
{
  val = digitalRead(buttonpin); 
  if (val == HIGH) 
  {
    digitalWrite(Led, HIGH);
    Serial.println("HIGH!");
  }
  else
  {
    digitalWrite(Led, LOW);
    Serial.println("LOW!");
  }
}
