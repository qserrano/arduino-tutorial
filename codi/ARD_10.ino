/*
 * CARTROTECH by Qode66 www.qode66.xyz
 * 10 - Sensor de temperatura i humitat DHT11
 * Codi: ARD_10
 * 02/05/2021
 */
 
#include <DHT.h>              // Incluim la  llibreria
 
#define DHTPIN 2              // Definir el pin digital on es connecta el sensor
#define DHTTYPE DHT11         // Definir el tipus de sensor
 

DHT dht(DHTPIN, DHTTYPE);     // Inicialitzar l'objecte DHT amb el nom dht
 
void setup() 
{
  
  Serial.begin(9600);         // Inicialitzar comunicació serie
  dht.begin();                // Inicialitzar el sensor DHT
 
}
 
void loop() 
{

  delay(5000);                          // Esperem 5 segons entre mesures  
  float h = dht.readHumidity();         // Llegir la humitat relatiava
  float t = dht.readTemperature();      // Llegir la temperatura en graus centigrados (per defecte)
  float f = dht.readTemperature(true);  // Llegir la temperatura en graus Farenheit 

  if (isnan(h) || isnan(t) || isnan(f)) // Comprovar si hi ha error en la lectura
  {  
    Serial.println("Error obtenint les dades del sensor DHT11");
    return;
  }
 

  float hif = dht.computeHeatIndex(f, h);         // Calcular l'index de calor en Fahreheit
  float hic = dht.computeHeatIndex(t, h, false);  // Calcular l'index de calor en graus centígrados
 
  Serial.print("Humitat: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Index de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
 
}
