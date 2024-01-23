
/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD013
 * Data: 30.08.2021
 * Descripcio: Enviar senyal per transmissor IR
 * Nota: Es deu connectar un modul transmissor IR al pin 3
 * 
 */

 #include <IRremote.h>
 
  IRsend irsend;
  
 void setup()
 {}
 
 void loop() 
 {
  digitalWrite(13,LOW);
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  digitalWrite(13,HIGH);
  irsend.sendRC5(0x1, 8); 
     delay(200); 
  }
 
