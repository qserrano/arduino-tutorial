/*
 * CARTROTECH  (www.cartrotech.cartrocreatiu.es)
 * 
 * Projecte nº: ARD021
 * Data: 06.11.2021
 * Descripcio: Modul deteccio so
 * Nota:
 * 
 */

int  sensorAnalogPin = A0;    // Pin d'entrada per la eixida analogica del sensor 
int  sensorDigitalPin = 7;    // Pin d'entrada per la eixida digital del sensor
int  analogValue = 0;         // Defineix la variable per guardar el valor analogic del sensor
int  digitalValue;            // Defineix la variable per guardar el valor digital del sensor
int  Led = 13;                // Defineix el pin LED, correspon al led muntat a la placa Arduino.
                              

void setup()
{
  Serial.begin(9600);               // Inicia el Monitor/Traçador del IDE
  pinMode(sensorDigitalPin,INPUT);  // Defineix el pin 7 com entrada digital
  pinMode(Led,OUTPUT);              // Defineix el pin Led (13) com eixida per indicar l'activacio del sensor
}

void loop(){
  analogValue = analogRead(sensorAnalogPin);  // Llig el valor en la entrada A0 i l'assigna a la variable analogValue 
  digitalValue=digitalRead(sensorDigitalPin); // Llig el valor en la entrada 7 i l'assigna a la variable digitalValue 
  Serial.println(analogValue); // Envia el valor analogic al monitor/traçador serie
  
  if(digitalValue==HIGH)      // Quan el sensor de so envia senyal alta, el led 13 s'ilumina
  {
    digitalWrite(Led,HIGH);
  }
  else
  {
    digitalWrite(Led,LOW);
  }
  
  delay(50);                  // Pausa per a no sobrecarregar la interface serie
}
