# 24 - Mòdul de sensor magnètic lineal

## Finalitat

En aquest experiment, aprendrem a usar el mòdul de sensor de corredor
lineal (KY024).

## Mòdul de sensor de corredor magnètic lineal

El Mòdul Sensor magnètic lineal KY024 pot detectar la presència d'un
camp magnètic prop del sensor. Variables com la intensitat del camp, la
polaritat i la posició de l'imant en relació amb el sensor afectaran el
punt en el qual l'eixida 'DO' canvia a un nivell alt (és a dir, alt
actiu). La sensibilitat del circuit es pot ajustar amb un potenciòmetre.

Un senyal d'eixida analògica del sensor està disponible en el pin
'AO'.

![Connexions del mòdul KY-024](../imatges/ard/ard_24_01.png)

## Material

|                               Imatge                               | Descripció                          |
| :----------------------------------------------------------------: | :---------------------------------- |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.           |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió                  |
| <img src="./../imatges/mat/mat_KY-028.png" width="50" height="50"> | Mòdul sensor magnètic lineal KY-024 |

## Hall sensor

_Especificacions_

![Especificacions](../imatges/ard/ard_24_02.png)

_Tensió d'eixida de l'efecte Hall_

![Output Hall-effect voltage](../imatges/ard/ard_24_03.png)

_Mecanismes de detecció_

![Mecanisme de detecció](../imatges/ard/ard_24_04.png)

## Factors de disseny: tipus magnètics

**Unipolar**: Només un pol sud operarà el sensor. El sensor s'encén amb
el pol sud (+) i s'apaga quan es lleva el pol sud.

**Bipolar**: l'eixida del sensor depén dels pols. Un pol sud (+) està
dissenyat per a activar el sensor; un pol nord (-) està dissenyat per a
desactivar-se. És possible que el sensor s'apague i encara estiga dins
d'un nivell de Gauss positiu.

**Enganxament**: Les especificacions són més estrictes en
l'enganxament. A vegades està dissenyat per a assegurar-se que quan es
lleva el pol sud (+) del sensor, romandrà encés fins que veja el pol
oposat (-).

**Omnipolar**: El sensor està dissenyat per a operar amb radiomètric
lineal: l'eixida és proporcional a la intensitat del camp magnètic. El
rang de sensibilitat d'eixida és de 2,5 a 3,75 mV per unitat de Gauss.

## Connexionat

![Connexionat](../imatges/ard/ard_24_05.png)
![Esquema elèctric](../imatges/ard/ard_24_06.png)

## Programació

**Codi ARD24a -- Eixida analogica**

```Arduino
/*
* Projecte nº: ARD024a
* Data: 11.11.2021
* Descripcio: Modul sensor magnetic lineal
* Nota: Eixida analogica
*
*/

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup()
{
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    sensorValue = analogRead(sensorPin);
    digitalWrite(ledPin, HIGH);
    delay(sensorValue);
    digitalWrite(ledPin, LOW);
    delay(sensorValue);
    Serial.println(sensorValue, DEC);
}
```

_Exemple de gràfica_

![Gràfica](../imatges/ard/ard_24_07.png)

**Codi ARD24b -- Eixida digitals**

```Arduino
/*
* Projecte nº: ARD024b
* Data: 11.11.2021
* Descripcio: Modul sensor magnetic lineal
* Nota: eixida digital
*
*/

int Led=13;
int buttonpin=3;
int val;

void setup()
{
    pinMode(Led,OUTPUT);
    pinMode(buttonpin,INPUT);
}

void loop()
{
    val=digitalRead(buttonpin);
    if(val==HIGH)
    {
        digitalWrite(Led,HIGH);
    }
    else
    {
        digitalWrite(Led,LOW);
    }
}
```

## Veure també

- [Index](../Index.md)
- [README](../README.md)
