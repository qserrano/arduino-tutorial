/*
 * CARTROTECH  (www.cartrotech.cartrocreatiu.es)
 * 
 * Projecte nº: ARD019
 * Data: 24.10.2021
 * Descripcio: Funcionament del led de doble color
 * Nota:
 * 
 */
 
int redpin = 11;   // pin per al led roig
int greenpin = 10;// pin per al led verd
int val;

void setup() 
{
  pinMode(redpin, OUTPUT);  //definim el pin roig com eixida
  pinMode(greenpin, OUTPUT);  //definim el pin verd com eixida
  Serial.begin(9600);  //iniciem el port de comunicació serial
}

void loop() 
{
  for(val = 255; val > 0; val--)  //seqüència de pas de roig a verd
  {
    analogWrite(redpin, val);
    analogWrite(greenpin, 255 - val);
    delay(10);
  }
  Serial.println("Verd");  //escribim al port sèrie el color actiu: verd
  delay(1000);
  
  for(val = 0; val < 255; val++)  //seqüència de pas de verd a roig
  {
    analogWrite(redpin, val);
    analogWrite(greenpin, 255 - val);
    delay(10); 
  }
  Serial.println("Roig");  //escribim al port sèrie el color actiu: roig
  delay(1000); 
}
