/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD022b
 * Data: 11.11.2021
 * Descripcio: Modul interruptor magnetic
 * Nota:
 * 
 */

int Led=13;       //defineix el port LED
int buttonpin=3; //defineix el port de l'interruptor
int  val;      //defineix la variable digital val
void  setup()
{
pinMode(Led,OUTPUT);//defineix LED com pin de eixida
pinMode(buttonpin,INPUT);//defineix la entrada digital del interruptor
}
void  loop()

{ val=digitalRead(buttonpin);//asigna el valor de la entrada 3 a val 
if(val==HIGH)//quan el sensor envia señal, LED s'encen
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
