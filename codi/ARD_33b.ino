/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
 * Projecte nº: ARD033b
 * Data: 01/02/2022
 * Descripcio: Prova de HC-SR04 sense biblioteca
 * Nota:
 * 
 */
 // Defineix pins Trig and Echo
#define trigPin 2
#define echoPin 3

// Defineix variables
long duration;
int distance;

void setup() 
{
  // Defineix entrades i eixides
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Inicia comunicació serie a 9600 bps
  Serial.begin(9600);
}

void loop() 
{
  // Llimpia trigPin ficant l’eixida a LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Dispara el sensor establint trigPin a HIGH per 10 microsegons:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Llig echoPin, pulseIn() torna la duració en microsegons:
  duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia
  distance = duration * 0.034 / 2;

  // Imprimeix la distancia en el monitor serie
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
}
