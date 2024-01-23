/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD028
 * Data: 22/01/2022
 * Descripcio: Lectura dels valors del joystick
 * Nota:
 * 
 */

const int SW_pin = 2; // pin digital per a boto
const int X_pin = A1; // pin analogic per a X
const int Y_pin = A0; // pin analogic per a Y

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Boto:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-eix: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-eix: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n");
  delay(500);
}
