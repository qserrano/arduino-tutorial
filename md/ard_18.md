# 18 - Mòdul foto-interruptor

## Objectius

- Conèixer el mòdul foto-interruptor

## Material

|                               Imatge                               | Descripció                      |
| :----------------------------------------------------------------: | :------------------------------ |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.       |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió              |
| <img src="./../imatges/mat/mat_KY-010.png" width="50" height="50"> | Mòdul foto-interruptor (KY-010) |
| <img src="./../imatges/mat/mat_KY-012.png" width="50" height="50"> | Mòdul brunzidor actiu (KY-012)  |

## Descripció

### Funcionament

El mòdul de foto-interruptor per a Arduino activarà un senyal quan es
bloquege la llum entre l'espai del sensor.

![Funcionament foto-interruptor](../imatges/ard/ard_18_01.jpeg)

### Especificacions

El mòdul de foto-interruptor consta d'un emissor / detector òptic en la
part davantera i dues resistències (1 kΩ i 33 Ω) en la part posterior.
El sensor utilitza un feix de llum entre l'emissor i el detector per a
comprovar si la trajectòria entre tots dos està bloquejada per un
objecte opac.

- Voltatge de funcionament: 3.3 ~ 5V
- Dimensions: 18,5 mm x 15 mm

## Connexió

Connecte la línia d'alimentació (enmig) i terra (esquerra) a + 5V i GND
respectivament. Connecte el senyal (S) al pin 3 del Arduino.

| Mòdul        | Arduino |
| ------------ | ------- |
| - (esquerra) | GND     |
| + (enmig)    | + 5V    |
| S (dreta)    | Pin 3   |

![Diagrama de muntatge foto-interruptor](../imatges/ard/ard_18_02.png)

Com podeu veure utilitzem un brunzidor actiu per emetre un so quan el
mòdul s'active.

![Esquema elèctric foto-interruptor](../imatges/ard/ard_18_03.png)

## Programació

**Codi: ARD_18**

```Arduino
/*
* Projecte nº: ARD018
* Data: 20.10.2021
* Descripcio: Funcionament del modul foto-interruptor
* Nota:
*
*/

int Led = 13; // defineix el pin de l'avisador
int buttonpin = 3; // defineix el pin de senyal del foto-interruptor
int val; //defineix una variable numerica

void setup()
{
  pinMode(Led, OUTPUT); // LED pin com eixida
  pinMode(buttonpin, INPUT); //Foto-interruptor pin com entrada
}

void loop()
{
  val=digitalRead(buttonpin); //llig el valor del sensor
  if(val == HIGH) // activa el led/avisador quan el sensor es bloqueja
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
