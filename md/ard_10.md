# 10 - Sensor de temperatura i humitat DHT11

## Finalitat

- Connexió de sensors
- Utilitzar llibreries específiques
- Captació d'informació d'elements exteriors
- Tractament de la informació

## Material

|                                 Imatge                                 | Descripció                                                           |
| :--------------------------------------------------------------------: | :------------------------------------------------------------------- |
|   <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">    | Arduino Uno o compatible amb S4A i amb el firmware per S4A carregat. |
| <img src="./../imatges/mat/mat_protoboard.png" width="50" height="50"> | Una protoboard                                                       |
|   <img src="./../imatges/mat/mat_cables.png" width="50" height="50">   | Cables de connexió                                                   |
|   <img src="./../imatges/mat/mat_KY-015.png" width="50" height="50">   | Un mòdul KY-015 o sensor DHT11                                       |

## Descripció

El DHT11 és un sensor digital de temperatura i humitat relativa de baix cost i fàcil ús. Integra un sensor capacitiu d'humitat i un termistor per a mesurar l'aire circumdant, i mostra les dades mitjançant un senyal digital en el pin de dades (no posseeix eixida analògica). Utilitzat en aplicacions acadèmiques relacionades al control automàtic de temperatura, aire condicionat, monitoratge ambiental en agricultura i més.

Utilitzar el sensor DHT11 amb les plataformes Arduino/Raspberry Pi/Nodemcu és molt senzill tant a nivell de programari com maquinari. A nivell de programari es disposa de llibreries per a Arduino amb suport per al protocol "Single bus". Quant al maquinari, només és necessari connectar el pin VCC d'alimentació a 3-5V, el pin GND a Terra (0V) i el pin de dades a un pin digital en el nostre Arduino. Si es desitja connectar diversos sensors DHT11 a un mateix Arduino, cada sensor ha de tindre el seu propi pin de dades. El protocol de comunicació entre el
sensor i el microcontrolador empra un únic fil o cable, la distància màxima recomanable de longitud de cable és de 20m., de preferència utilitzar cable amb malla.

Potser l'únic desavantatge del sensor és que només es pot obtindre noves dades cada 2 segons.

### Característiques bàsiques

| **DHT11**       |                |
| :-------------- | :------------- |
| Alimentació     | de 3,5 V a 5 V |
| Consum          | 2,5 mA         |
| Senyal d'eixida | Digital        |

| **Temperatura** |               |
| :-------------- | :------------ |
| Rang            | de 0ºC a 50ºC |
| Precisió        | A 25ºC ± 2ºC  |
| Resolució       | 1ºC (8-bit)   |

| **Humitat relativa** |                          |
| :------------------- | :----------------------- |
| Rang                 | de 20% HR a 90% HR       |
| Precisió             | Entre 0ºC y 50ºC ± 5% HR |
| Resolució            | 1% HR                    |

Podeu veure la fulla de característiques aquí
[DHT11-DataSheet](../datasheet/DHT11%20-%20Temperature%20and%20Humidity%20Module.pdf) (en)

## Muntatge

Com tenim dues versions del sensor de temperatura i humitat DHT11, veurem com hauríem de connectar-lo a Arduino en els dos casos. Recorda que treballarem amb un pin digital. En els dos casos , l'alimentació pot ser de 3,5 V o 5 V.

Consideracions prèvies:

- La resistència **pull-up** de 5 kΩ és la recomanada per a un cable de longitud de fins a **20 m**. Si connectes un cable major al DHT11, la resistència pull-up haurà de ser proporcional.
- Compte si alimentes el DHT11 amb 3,5 V. En aquest cas, el cable d'alimentació no ha de ser major de **20 cm** pel fet que les caigudes de tensió poden provocar mal funcionament.
- Es recomana prendre mesures cada **5 segons**. Si s'utilitza un període menor pot ocasionar que les dades no siguen precises.

### DHT11 sense pcb

![sensor-dht11](../imatges/ard/ard_10_01.png)

Per a connectar el circuit d'una aplicació típica amb un DHT11, necessitarem tindre una resistència pull-up connectada a l'eixida digital. La recomanació és utilitzar una resistència de 5 kΩ. Disposem de 4 pins:

- VCC (de 3,5V a 5V)
- l'eixida digital I/O
- el pin no connectat NC
- la presa de terra GND.

L'esquema elèctric i de muntatge del DHT11 seria el següent:

![esquema-muntatge](../imatges/ard/ard_10_02.png)
![esquema-electric](../imatges/ard/ard_10_03.png)

### DHT11 amb pcb (KY-015)

Al contrari que l'altre model, el DHT11 integrat dins d'un PCB (Printed Circuit Board) ja ve amb la resistència pull-up integrada. Pot resultar molt útil a vegades, però si afegim un cable de més de 20 metres, haurem de tindre en compte aquest factor.

Aquest model de DHT11 disposa de 3 pins, la presa de terra GND, per a les dades DATA i per a l'alimentació VCC (de 3,5V o 5V).

En la següent imatge pots veure l'esquema de connexió amb Arduino.

![esquema-muntatge-ky015](../imatges/ard/ard_10_04.png)
![esquema-electric-ky015](../imatges/ard/ard_10_05.png)

## Programació

Tant el sensor DHT11 com el mòdul KY-015 utilitzen el seu propi protocol de comunicació bidireccional mitjançant un únic conductor, emprant senyals temporitzades.

Per a simplificar el procés de lectura de dades tenim a disposició llibreries preparades. Hi ha diverses llibreries que podem utilitzar per a obtindre la informació de temperatura i humitat. En aquest cas utilitzarem la que ens proporciona [Adafruit](https://github.com/adafruit/DHT-sensor-library). Aquesta llibreria és molt senzilla d'utilitzar i funciona per als dos models, DHT11 amb PCB i sense PCB.

Amb aquesta llibreria obtindrem tres valors:

- Humitat relativa: descriu la quantitat d'aigua que es transporta per l'aire, és important per a determinar el desenvolupament dels núvols i el factor precipitació.
- Temperatura ambient: temperatura en un determinat lloc.
- Índex de calor: indica quant calor fa tenint en compte la humitat relativa i la temperatura.Ens dona una idea de la sensació de calor.

### Anàlisi del codi

#### Declaracions prèvies

```Arduino

#include <DHT.h> // Incluim la llibreria
#define DHTPIN 2 // Definir el pin digital _on_ es connecta el sensor
#define DHTTYPE DHT11 // Definir el tipus de sensor

DHT dht(DHTPIN, DHTTYPE); // _Declarar_ l'objecte DHT amb el nom dht

```

La primera línia inclou la llibreria DHT.h al nostre programa per que puguem fer ús d'ella.

Després venen dues definicions d'objectes, DHTPIN indica quin pin digital fem servir per comunicar-nos amb el sensor i DHTTYPE indica el tipus de sensor.

Amb aquestes definicions, configurem la instància DHT amb el nom dht i li passem els valors necessaris. Podem dir que la llibreria està en funcionament i li demanarem les dades quan ens interesse.

#### Funció setup()

```Arduino

void setup()
{
  Serial.begin(9600); // Inicialitzar comunicació serie
  dht.begin(); // Inicialitzar l'objecte DHT
}

```

En aquesta secció preparem el port sèrie i els sensor per a la comunicació.

#### Funció loop()

```Arduino

void loop()
{
  delay(5000); // Esperem 5 segons entre mesures
  float h = dht.readHumidity(); // Llegir la humitat relatiava
  float t = dht.readTemperature(); // Llegir la temperatura en graus centigrados
  float f = dht.readTemperature(true); // Llegir la temperatura en graus Farenheit
  ...

```

Dins de la funció loop() que es repetirà contínuament incloem primerament un retard de 5000 ms per donar temps al sensor a replegar la informació a transmetre.

Les següents ordres tenen dues parts. La primera part és una declaració de variable float per replegar la dada requerida (float «nom_variable») i la segon part fa ús de l'ordre reservada per demanar al sensor la informació pertinent.

```Arduino

  if (isnan(h) || isnan(t) || isnan(f)) // Comprovar si hi ha error en la lectura
  {
    Serial.println("Error obtenint les dades del sensor DHT11");
    return;
  }
  ...
```

Comprovació d'errors, la funció «isnan(variable)» en retorna el valor TRUE si la variable no és un número (Is Not A Number).

```Arduino
  float hif = dht.computeHeatIndex(f, h); // Calcular l'index de calor en Fahreheit
  float hic = dht.computeHeatIndex(t, h, false); // Calcular l'index de calor en graus centígrados
  ...
```

Un altra vegada declarem variables float i demanem al sensor que ens
retorne la informació «index de calor» amb la crida reservada per a
l'objecte dht.

Per finalitzar enviem la informació capturada al monitor serie per mig
de la comunicació serie.

```Arduino

    Serial.print("Humitat: ");
    Serial.print(h);
    Serial.print(" %t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F");
    Serial.print("Index de calor: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");

}
```

## Codi complet

Teniu el codi complet [aquí](../codi/ARD_10.ino)

```Arduino

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
```

## Conceptes importants

- Inclusió de llibreries predefinides
- Declaració d'objectes
- Tractament de la informació

## Veure també

- [Index](../Index.md)
- [README](../README.md)
