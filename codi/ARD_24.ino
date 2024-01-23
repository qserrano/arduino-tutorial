/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD024
 * Data: 13/01/2022
 * Descripcio: Sensor magnetic KY024
 * Nota:
 * 
 */
 
int led = 13 ; // LED en arduino
int digitalPin = 3; // KY024 entrada digital
int analogPin = A0; // KY024 entrada analogic
int digitalVal ; // variable lectura digital
int analogVal; // variable lectura analogica
void setup ()
{
  pinMode (led, OUTPUT); 
  pinMode (digitalPin, INPUT); 
  //pinMode(analogPin, INPUT); 
  Serial.begin(9600);
}

void loop ()
{
  // Llig valor digital
  digitalVal = digitalRead(digitalPin) ; 
  if (digitalVal == HIGH) 
  {
    digitalWrite (led, HIGH);
  }
  else
  {
    digitalWrite (led, LOW);
  }
  
  // Llig valor analogic
  analogVal = analogRead(analogPin);
  Serial.println(analogVal); 

  delay(100);
}
