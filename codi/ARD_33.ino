/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD033
 * Data: 01/02/2022
 * Descripcio: Prova del HC-SR04 amb bibliteca
 * Nota:
 * 
 */
 
#include <NewPing.h>

#define TRIGGER_PIN  2  
#define ECHO_PIN     3  
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  delay(500);  
  unsigned int uS = sonar.ping(); 
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
}
