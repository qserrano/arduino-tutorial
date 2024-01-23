/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD017b
 * Data: 19.10.2021
 * Descripcio: Colors aleaotoris en led rgb
 * Nota: El modul LED RGB SMD necessite resistencies llimitadores
 * 
 */

int redpin = 11; //selecciona el pin per a LED roig
int greenpin = 10; // selecciona el pin per a LED verd
int bluepin = 9;// selecciona el pin per a LED blau
int randomRed;
int randomGreen;
int randomBlue;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  randomRed = random(1,127);
  randomGreen = random(1,127);
  randomBlue = random(1,127);

  analogWrite(redpin, randomRed);
  analogWrite(greenpin, randomGreen);
  analogWrite(bluepin, randomBlue);
  
  delay(1000);
}
