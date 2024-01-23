
/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD014
 * Data: 30.08.2021
 * Descripcio: Fer sonar el buzzer actiu
 * Nota:
 * 
 */
int buzzerPin = 8;

void setup ()
{
  pinMode (buzzerPin, OUTPUT);
}

void loop ()
{
  digitalWrite (buzzerPin, HIGH);
  delay (500);
  digitalWrite (buzzerPin, LOW);
  delay (500);
}
