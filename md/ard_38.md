# 38 - Mòdul de teclat

## Descripció general

En aquest projecte, veurem com integrar un teclat amb una placa UNO R3
perquè puga llegir les tecles que pressiona un usuari.

Els teclats s'utilitzen en tota mena de dispositius, inclosos telèfons
mòbils, màquines de fax, microones, forns, panys de portes, etc. Estan
pràcticament a tot arreu. Tones de dispositius electrònics els usen per
a l'entrada de l'usuari. Per tant, saber com connectar un teclat a un
microcontrolador com una placa UN R3 és molt valuós per a construir
molts tipus diferents de productes comercials.

Al final, quan tot està correctament connectat i programat, quan es
pressiona una tecla, apareix en el monitor serie de la seua computadora.
Cada vegada que pressiona una tecla, apareix en el monitor serie. Per a
simplificar, comencem simplement mostrant la tecla pressionada en la
computadora.

Per a aquest projecte, el tipus de teclat que usarem és un teclat
matricial. Aquest és un teclat que segueix un esquema de codificació que
li permet tindre molts menys pins d'eixida que tecles.

Per exemple, el teclat de matriu que estem usant té 16 tecles (0-9,
A-D,\*, #), però només 8 pins d'eixida. Amb un teclat lineal, hauria
d'haver-hi 17 pins d'eixida (un per a cada tecla i un pin de terra)
perquè funcione. L'esquema de codificació matricial permet menys pins
d'eixida i, per tant, moltes menys connexions que han de realitzar-se
perquè el teclat funcione. D'aquesta manera, són més eficients que els
teclats lineals, ja que tenen menys cablejat.

![Mòdul de teclat](../imatges/ard/ard_38_01.png)

## Material

|                               Imatge                               | Descripció                |
| :----------------------------------------------------------------: | :------------------------ |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent. |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió        |
| <img src="./../imatges/mat/mat_teclat.png" width="50" height="50"> | Mòdul de teclat matricial |

## Connexió

![Esquema elèctric](../imatges/ard/ard_38_02.png)
![Cablejat](../imatges/ard/ard_38_03.png)

Per a connectar els pins a la placa UNO R3, els connectem als pins
d'eixida digital, D9-D2. Connectem el primer pin del teclat a D9, el
segon pin a D8, el tercer pin a D7, el quart pin a D6, el cinqué pin a
D5, el sisé pin a D4, el seté pin a D3 i el huité pin a D2.

Aquesta és la taula de connexions:

| Pin teclat | Pin arduino |
| :--------: | :---------: |
|     1      |     D9      |
|     2      |     D8      |
|     3      |     D7      |
|     4      |     D6      |
|     5      |     D5      |
|     6      |     D4      |
|     7      |     D3      |
|     8      |     D21     |

## Programacio

```Arduino

/*
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
char hexaKeys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'\*','0','\#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connecteu-los als pins de fila del teclat
byte colPins[COLS] = {5, 4, 3, 2}; //connecteu-los als pins de columna del teclat

//inicialitza una instancia de la classe Newkepad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    Serial.println(customKey);
  }
}
```

## Descàrrega

- [Codi ARD038](https://mega.nz/folder/2KoSwaTa#AxDfZl3717MrwnJ2LUacew)
- [Fritzing part keypad 4x4](https://mega.nz/file/LXgWTI6I#fNptqZc9mlxgrD5jFckcs6ne6uef0DAioNTZ8yscEWs)

## Veure també

- [Index](../Index.md)
- [README](../README.md)
