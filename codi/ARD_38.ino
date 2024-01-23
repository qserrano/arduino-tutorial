/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD038
 * Data: 11/02/2022
 * Descripcio: prova del teclat matricial
 * Nota:
 * 
 */
 
#include <Keypad.h>

const byte ROWS = 4; //quatre files
const byte COLS = 4; //quatre columnes
//defineix els simbols dels polsador del teclat
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connecteu-los als pins de fila del teclat
byte colPins[COLS] = {5, 4, 3, 2}; //connecteu-los als pins de columna del teclat

//inicialitza una instancia de la classe Newkepad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
