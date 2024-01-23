/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD32
 * Data: 31/01/2022
 * Descripcio: Prova del modul rele
 * Nota:
 * 
 */
 
int relayPin = 3;
 
void setup() 
{ 
  pinMode(relayPin, OUTPUT);
} 
 
 
void loop() 
{ 
  digitalWrite(relayPin, HIGH);    
  delay(2000);                     
  digitalWrite(relayPin, LOW);    
  delay(2000);                  
} 
