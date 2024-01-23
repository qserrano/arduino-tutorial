
/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD013
 * Data: 30.08.2021
 * Descripcio: Rebre senyal del transmissor IR
 * Nota:
 * 
 */

 #include <IRremote.h>
 
 #define RECV_PIN  11        //Pin de recepcio del senyal IR
 #define LED       13        //defineix LED pin
 
 IRrecv irrecv(RECV_PIN);    //crear l'objecte irrecv per al receptor IR en el pin indicat
 decode_results results;     //declarem la variable results (dades de la recepcio)
 
 void setup()
 { 
   pinMode(LED, OUTPUT); //inicialitza LED com eixida
   Serial.begin(9600);
   irrecv.enableIRIn(); //activa l'objecte irrecv
 }
 
  void loop() 
 {
  if (irrecv.decode(&results))       //comprovem si arrivan dades
   { 
     int state;
       if ( results.value == 1 )  
       {    
         state = HIGH;
       }
       else
       {
        state = LOW;
       }
    digitalWrite( LED, state );     
    Serial.println(results.value);
    irrecv.resume();                 // comencem una nova recepcio
   }
 }
