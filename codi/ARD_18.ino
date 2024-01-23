/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD018
 * Data: 20.10.2021
 * Descripcio: Funcionament del modul foto-interruptor
 * Nota: 
 * 
 */

int Led = 13; // defineix el pin de l'avisador
int buttonpin = 3; // defineix el pin de senyal del foto-interruptor
int val; //defineix una variable numerica

void setup()
{
  pinMode(Led, OUTPUT); // LED pin com eixida
  pinMode(buttonpin, INPUT); //Foto-interruptor pin com entrada
}

void loop()
{
  val=digitalRead(buttonpin); //llig el valor del sensor 
  if(val == HIGH) // activa el led/avisador quan el sensor es bloqueja
  {
    digitalWrite(Led,HIGH);
  }
  else
  {
    digitalWrite(Led,LOW);
  }
}
