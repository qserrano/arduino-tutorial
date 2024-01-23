/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD016a
 * Data: 16.10.2021
 * Descripcio: Encen i apaga el laser
 * Nota:
 * 
 */

void setup ()
{
  pinMode (9, OUTPUT);     // defineix el pin 9 com eixida digital
}

void loop () 
{
  digitalWrite (9, HIGH);   // activa el laser
  delay (1000);       // espera 1 seg
  digitalWrite (9, LOW);  // apaga el laser
  delay (1000);       // espera 1 seg
}
