/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD026b
 * Data: 19/01/2022
 * Descripcio: Us de la eixida digital del sensor tactil
 * Nota:
 * 
 */
 
int Led=13;//pin per al LED
int buttonpin=3; //eixida DO del sensor
int DOval;//variable digital
void  setup()
{
pinMode(Led,OUTPUT);//define LED as a output port
pinMode(buttonpin,INPUT);//define switch as a output port
}
void  loop()

{ DOval=digitalRead(buttonpin);//read the value of the digital interface 3 assigned to val 
if(DOval==HIGH)//when the switch sensor have signal, LED blink
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
