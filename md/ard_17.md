# 17 - Mòdul led RGB SMD i mòdul led RGB

## Objectiu

En aquest experiment, aprendrem a utilitzar el mòdul LED SMD RGB i el
mòdul LED RGB.

## Material

|                               Imatge                               | Descripció                 |
| :----------------------------------------------------------------: | :------------------------- |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.  |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió         |
| <img src="./../imatges/mat/mat_KY-009.png" width="50" height="50"> | Mòdul LED RGB SMD (KY-009) |
| <img src="./../imatges/mat/mat_KY-016.png" width="50" height="50"> | Mòdul LED RGB (KY-016)     |

## Introducció

En realitat, la funció del mòdul LED SMD RGB (KY-009) i del mòdul LED
RGB (KY-016) és quasi la mateixa, però podem triar la forma que ens
agrade o que necessitem.

El mòdul LED SMD RGB i el mòdul LED RGB estan fets per tres leds (roig,
verd i blau). En ajustar l'entrada de voltatge dels pins R (roig), G
(verd), B (blau), podem ajustar la intensitat dels tres colors primaris
(roig / blau / verd) per a obtindre tots els colors.

## Característiques

### Mòdul LED RGB SMD (KY-009)

![Mòdul led rgb smd](../imatges/ard/ard_17_01.jpeg)

#### Descripció

Mòdul LED RGB a tot color per a Arduino, emet una gamma de colors
mesclant llum roja, verda i blava. La quantitat de cada color s'ajusta
mitjançant modulació per control de pulsos (PWM).

#### Especificacions

El mòdul LED SMD a tot color RGB consta d'un LED SMD 5050, que**
s'utilitza** **amb resistències limitadores** per a evitar que es
creme. Compatible amb plataformes electròniques populars com Arduino,
Raspberry Pi i ESP8266.

- Tensió de funcionament: 5 V màx.
  - Roig: 1.8V ~ 2.4V
  - Verd: 2.8V ~ 3.6V
  - Blau: 2.8V ~ 3.6V
- Corrent directa: 20mA ~ 30mA
- Temp. de funcionament: -25 ° C a 85 ° C
- Dimensions: 18,5 mm x 15 mm

### Mòdul LED RGB (KY-016)

![Mòdul led rgb](../imatges/ard/ard_17_02.jpeg)

#### Descripció

Arduino LED RGB de 5 mm a tot color, es poden obtindre diferents colors
mesclant els tres colors primaris.

#### Especificacions

Aquest mòdul consta d'un LED RGB de 5 mm i tres resistències
limitadores de 150 Ω per a evitar que es creme. L'ajust del senyal PWM
en cada pin de color donarà com a resultat diferents colors.

- Voltatge de funcionament: 5 V
- Control: Mètode de càtode comú
- LED diàmetre: 5 mm
- Dimensions: 15 mm x 19 mm

## Muntatge

### Mòdul LED RGB SMD

![Muntatge led rgb](../imatges/ard/ard_17_03.png)
![Esquema elèctric led rgb](../imatges/ard/ard_17_04.png)

**Important:** aquest mòdul deu funcionar amb resistències per limitar
la intensitat. Si no teniu els valors indicats podeu utilitzar tres
resistències de 220Ω.

Nota: Al meu muntatge he tingut que intercanviar el cable roig i el
verd. O bé el sensor està mal indicat, o bé té un error de fabricació.

### Mòdul LED RGB

![Muntatge led rgb smd](../imatges/ard/ard_17_05.png)
![Esquema eléctric led rgb smd](../imatges/ard/ard_17_06.png)

Aquest muntatge no necessita de resistències. Tampoc cal una protoboard
perquè podem connectar el sensor directament amb els cables.

## Programació

Presentem dos codis com exemple. El primer varia la intensitat de cada
component de color (roig, verd i blau) per separat i després la unió de
dos dels components. El segon codi mostra colors aleatoris per
combinació dels tres canals.

Codi: ARD_17a

```Arduino
/*
* Projecte nº: ARD017
* Data: 19.10.2021
* Descripcio: Exemple de colors amb led rgb
* Nota: Si s'utilitza un led rgb smd, recordeu ficar resistencies llimitadores
*
*/

int redpin = 11; //selecciona el pin per a LED roig
int greenpin = 10; // selecciona el pin per a LED verd
int bluepin = 9;// selecciona el pin per a LED blau
int val;

void setup()
{
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for(val = 0; val \< 255; val++) //encen progressivament el led roig
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, 0);
    Serial.println(val);
    delay(10);
  }
  for(val = 0; val \< 255; val++) //encen progresivament el led blau
  {
    analogWrite(redpin, 0);
    analogWrite(bluepin, val);
    analogWrite(greenpin, 0);
    Serial.println(val);
    delay(10);
  }
  for(val = 0; val \< 255; val++) //encen progresivament el led verd
  {
    analogWrite(redpin, 0);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, val);
    Serial.println(val);
    delay(10);
  }
  for(val = 0; val \< 255; val++) //encen progresivament el led roig i blau
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, val);
    analogWrite(greenpin, 0);
    Serial.println(val);
    delay(10);
  }
  for(val = 0; val \< 255; val++) //encen progresivament el led roig i verd
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, 0);
    analogWrite(greenpin, val);
    Serial.println(val);
    delay(10);
  }
  for(val = 0; val \< 255; val++) //encen progresivament el led blau i verd
  {
    analogWrite(redpin, 0);
    analogWrite(bluepin, val);
    analogWrite(greenpin, val);
    Serial.println(val);
    delay(10);
  }
}
```

Codi: ARD_17b

```Arduino
/*
* Projecte nº: ARD017b
* Data: 19.10.2021
* Descripcio: Colors aleatoris amb led rgb
* Nota: Si s'utilitza un led rgb smd, recordeu ficar resistencies llimitadores
*
*/

int redpin = 11; //selecciona el pin per a LED roig
int greenpin = 10; // selecciona el pin per a LED verd
int bluepin = 9;// selecciona el pin per a LED blau
int randomRed;
int randomGreen;
int randomBlue;

void setup()
{
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  randomRed = random(1,127);
  randomGreen = random(1,127);
  randomBlue = random(1,127);
  analogWrite(redpin, randomRed);
  analogWrite(greenpin, randomGreen);
  analogWrite(bluepin, randomBlue);
  delay(1000);
}
```

## Resum

- Presentació del mòduls LED RGB i LED RGB SMD
- Utilitat i funcionament dels pins del mòdul

## Veure també

- [Index](../Index.md)
- [README](../README.md)
