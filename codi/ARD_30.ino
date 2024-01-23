/*
   CARTROTECH  (www.cartrotech.wordpress.com)

   Projecte nº: ARD030
   Data: 27/0º/2022
   Descripcio: Prova del sensor d'evitar obstacles
   Nota:

*/

int Led = 13;
int buttonpin = 3;
int  val;
void  setup()
{
  pinMode(Led, OUTPUT);
  pinMode(buttonpin, INPUT);
}
void  loop()
{ 
  val = digitalRead(buttonpin);
  if (val == HIGH)
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);
  }
}
