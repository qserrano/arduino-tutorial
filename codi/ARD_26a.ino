/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD026a
 * Data: 19/01/2022
 * Descripcio: Us de la eixida analogica del sensor tactil
 * Nota:
 * 
 */
 
int  sensorPin  =  A0;     // pin d'entrada del potenciometre 
int  ledPin  =  13;   // pin per al LED
int  sensorValue =  0;  // variable valor del sensor

void setup()
{
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}
void loop()
{
sensorValue =  analogRead(sensorPin);
digitalWrite(ledPin,  HIGH); 
delay(sensorValue); 
digitalWrite(ledPin,  LOW);
delay(sensorValue);
Serial.println(sensorValue,  DEC);
}
