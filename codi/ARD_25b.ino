/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD025b
 * Data: 16/01/2022
 * Descripcio: Llig valor analogic del sensor
 * Nota:
 * 
 */
 
int  sensorPin  =  A0;     // select the input  pin for  the potentiometer 
int  ledPin  =  13;       // select the pin for  the LED
int  sensorValue =  0;  // variable to  store  the value  coming  from  the sensor

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
