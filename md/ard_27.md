# 27 -- Mòdul led flash de set colors

## Descripció general

En aquest experiment, aprendrem a usar el mòdul LED de flaix de set
colors.

## Mòdul led flash de set colors

LED transparent de 5 mm per a funcionament directe des de 5V. El color
del LED canvia automàticament a través d\'una seqüència de set colors.
L'alimentació de 5 V es connecta al pin \'S\' i es connecta a terra el
pin central.

![Pins del mòdul KY-034](../imatges/ard/ard_27_01.png)

## Material

|                               Imatge                               | Descripció                           |
| :----------------------------------------------------------------: | :----------------------------------- |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.            |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió                   |
| <img src="./../imatges/mat/mat_KY-034.png" width="50" height="50"> | Un mòdul led flash de 7 colors KY034 |

## Components

### Led flash de set colors

El mòdul LED intermitent de 7 colors utilitza automàticament un díode
emissor de llum redó d\'alta lluentor de 5 mm que té les següents
característiques:

- Tipus de producte: LED
- Model del producte: YB-3120B4 Pn YG-PM
- Forma: LED redó tipus DIP de 5 mm
- Color: rosa groc verd (alta lluentor) Tipus de lent: boira blanca
- Voltatge directe estàndard: 3.0-4 .5V

## Connexions

![Esquema elèctric mòdul KY-034](../imatges/ard/ard_27_02.png)
![Cablejat mòdul KY-034](../imatges/ard/ard_27_03.png)

## Programació

Codi: ARD027

```Arduino
/*
* Projecte nº: ARD027
* Data: 20/01/2022
* Descripcio: Us del led flash de 7 colors
* Nota: Encen el LED i va repetint la sequencia
*/

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
}
```

## Veure també

- [Index](../Index.md)
- [README](../README.md)
