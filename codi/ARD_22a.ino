/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD022a
 * Data: 11.11.2021
 * Descripcio: Modul interruptor magnetic
 * Nota:
 * 
 */

int  sensorPin  =  A0;     // defineix la entrada analogica del sensor 
int  ledPin  =  13;      // eixida led per veure l'activacio
int  sensorValue =  0;  // variable per guardar el valor del sensor

void setup()
{
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop(){
sensorValue =  analogRead(sensorPin);
digitalWrite(ledPin,  HIGH); 
delay(sensorValue); 
digitalWrite(ledPin,  LOW);
delay(sensorValue);
Serial.println(sensorValue,  DEC);
}
