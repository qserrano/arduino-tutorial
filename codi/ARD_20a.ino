/*
 * CARTROTECH  (www.cartrotech.cartrocreatiu.es)
 * 
 * Projecte nº: ARD020a
 * Data: 01.11.2021
 * Descripcio: Modul LDR - fotoresistencia
 * Nota:
 * 
 */

int sensorPin = A0; // defineix l’entrada per a la fotoresistència
int ledPin = 13; // defineix el pin led
int sensorValue = 0; // variable per a guardar el valor del sensor

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
  Serial.println(sensorValue, DEC);

}
