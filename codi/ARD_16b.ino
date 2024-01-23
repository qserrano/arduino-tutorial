/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD016b
 * Data: 17.10.2021
 * Descripcio: Pujar i baixar la intensitat del laser
 * Nota:
 * 
 */

int laser = 0;  //defineix la variable laser    

void setup() 
{
  pinMode(9,OUTPUT);  //configura el pin 9 com eixida
}

void loop() 
{
  for (laser = 0; laser <= 255; laser += 1) 
  { 
    analogWrite(9,laser);    //escriu en el pin 9 el valor de laser          
    delay(5);               //espera 5 mil·lisegons        
  }
  for (laser = 255; laser >= 0; laser -= 1) 
  { 
    analogWrite(9,laser);             
    delay(5);                      
  }
}
