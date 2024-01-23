/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD012
 * Data: 29.08.2021
 * Descripcio: Llegir un polsador i fer parpellejar el led del pin 13
 * 
 */

int Led = 13;  //Assigna el pin Led
int pols = 3;  //Assigna el pin al polsador
int val;       //Defineix una variable

void setup() 
{
  
  pinMode(Led, OUTPUT);  //Configura el pin 13 (Led) com eixida
  pinMode(pols, INPUT);  //Configura el pin 3 (pols) com entrada

}

void loop() 
{

  val = digitalRead (pols);  //llig el valor de l'entrada 3 i l'assigna a val
  if (val == HIGH)
  {
    digitalWrite (Led,LOW);
  }
  else
  {
    digitalWrite (Led,HIGH);
    delay(200);
    digitalWrite (Led,LOW);
    delay(200);
  }

}
