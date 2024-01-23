/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD017
 * Data: 19.10.2021
 * Descripcio: Mostra progressivament els canals i les combinacions entre ells
 * Nota: El modul LED RGB SMD necessita resistencies llimitadores
 * 
 */

int redpin = 11; //selecciona el pin per a LED roig
int greenpin = 10; // selecciona el pin per a LED verd
int bluepin = 9;// selecciona el pin per a LED blau
int val;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  for(val = 0; val < 255; val++) //encen progressivament el led roig
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, 0);
    Serial.println(val);
    delay(10); 
  }
  for(val = 0; val < 255; val++)  //encen progresivament el led blau
  {
    analogWrite(redpin, 0);
    analogWrite(bluepin, val);
    analogWrite(greenpin, 0);
    Serial.println(val);
    delay(10); 
  }  
  for(val = 0; val < 255; val++)  //encen progresivament el led verd
  {
    analogWrite(redpin, 0);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, val);
    Serial.println(val);
    delay(10); 
  }
  for(val = 0; val < 255; val++)  //encen progresivament el led roig i blau
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, val);
    analogWrite(greenpin, 0);
    Serial.println(val);
    delay(10); 
  }
  for(val = 0; val < 255; val++)  //encen progresivament el led roig i verd
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, val);
    Serial.println(val);
    delay(10); 
  }
  for(val = 0; val < 255; val++)  //encen progresivament el led blau i verd
  {
    analogWrite(redpin, 0);
    analogWrite(bluepin, val);
    analogWrite(greenpin, val);
    Serial.println(val);
    delay(10); 
  }  
}
