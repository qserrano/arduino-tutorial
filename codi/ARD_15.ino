
/*
 * CARTROTECH  (www.cartrocreatiu.es)
 * 
 * Projecte nº: ARD015
 * Data: 07.10.2021
 * Descripcio: Fer sonar el buzzer passiu
 * Nota:
 * 
 */
 
int buzzer = 8; // estableix el pin digital de control del buzzer

void setup() {
  pinMode(buzzer, OUTPUT); // configura el pin 8 com eixida
}

void loop() {
  for (int i = 0; i < 80; i++) {  // crea un so de 500 Hz
    digitalWrite(buzzer, HIGH); // envia senyal alta al buzzer 
    delay(1); // delay 1ms
    digitalWrite(buzzer, LOW); // envia senyal baixa al buzzer
    delay(1);
  }
  delay(50);
  for (int j = 0; j < 100; j++) { //crea un so de 250 HZ
    digitalWrite(buzzer, HIGH);
    delay(2); // delay 2ms
    digitalWrite(buzzer, LOW);
    delay(2);
  }
  delay(100);
}
