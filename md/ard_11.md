# 11 - La pantalla LCD

## Finalitat

- Muntatge d'una pantalla LCD de 16x02
- Enviar informació a la pantalla LCD
- Còm definir caracters especials

## Material

|                                  Imatge                                   | Descripció                                                           |
| :-----------------------------------------------------------------------: | :------------------------------------------------------------------- |
|     <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">     | Arduino Uno o compatible amb S4A i amb el firmware per S4A carregat. |
|  <img src="./../imatges/mat/mat_protoboard.png" width="50" height="50">   | Una protoboard                                                       |
|    <img src="./../imatges/mat/mat_cables.png" width="50" height="50">     | Cables de connexió                                                   |
| <img src="./../imatges/mat/mat_potenciometre.png" width="50" height="50"> | Un potenciòmetre                                                     |
|   <img src="./../imatges/mat/mat_LCD16x02.png" width="50" height="50">    | Una pantalla LCD 16x02                                               |

## Descripció del material

La pantalla LCD-1602 és una pantalla de cristall líquid de 16 caràcters de 2 línies de baixa potència, amb interfície sèrie. Podeu descarregar la fulla de característiques (en anglés)
[aquí](../datasheet/LCD1602A.pdf).

![pantalla-lcd](../imatges/ard/ard_11_01.png)

Les pantalles LCD (Liquid Cristall Display) són una de les formes més senzilles i econòmiques de dotar d'un display a un autòmat.

El Hitachi HD44780 és un dels controladors de LCDs més àmpliament estesos per la seua senzillesa i baix preu. L'HD44780 està dissenyat per a controlar LCDs monocroms de fins a 80 caràcters alfanumèrics i símbols. També disposa d'una xicoteta memòria RAM per a configurar els nostres propis caràcters o dibuixos.

Les pantalles LCD amb el controlador HD44770 es fabriquen en diferents grandàries, sent comunes 16x02 (2 línies de 16 caràcters), 20x02, 20x04 i 40x02.

Les pantalles LCD disposen de retroil·luminació posterior en blava o en verd. El contrast pot ser variat connectant un potenciòmetre al LCD.

Connectar directament un LCD a Arduino requereix una gran quantitat de pins. Sol ser aconsellable emprar un **adaptador a bus I2C**, com veurem en la propera entrada.

## Muntatge

![esquema-muntatge](../imatges/ard/ard_11_02.png)
![esquema-electric](../imatges/ard/ard_11_03.png)

Com podeu veure són necessaris un bon número de cables per fer les connexions, així que és molt fàcil equivocar-se. Per això es recomana utilitzar un mòdul I2C, que simplifica moltíssim el muntatge.

La relació dels pins i la seua connexió tant per al arduino com per a la pantalla és la següent:

|          | LCD                                        | Arduino              |
| :------- | :----------------------------------------- | :------------------- |
| 01 - GND | negatiu pantalla                           | GND                  |
| 02 - Vcc | positiu pantalla                           | 5V                   |
| 03 - V0  | ajust del contrast                         | Pot 10K pin variable |
| 04 - RS  | registre de senyal de selecció             | Pin 12               |
| 05 - R/W | senyal de selecció de lectura / escriptura | GND                  |
| 06 - E   | senyal d'activació d'operació              | Pin 11               |
| 07 - D0  |                                            |                      |
| 08 - D1  |                                            |                      |
| 09 - D2  |                                            |                      |
| 10 - D3  |                                            |                      |
| 11 - D4  | Transferència de dades                     | Pin 05               |
| 12 - D5  | Transferència de dades                     | Pin 04               |
| 13 - D6  | Transferència de dades                     | Pin 03               |
| 14 - D7  | Transferència de dades                     | Pin 02               |
| 15 - A   | il·luminació de fons                       | 5V                   |
| 16 - K   | il·luminació de fons                       | GND                  |

---

## Programació

Per aquest muntatge pujarem el exemple contingut en «Fitxer>Exemples>LiquidCrystal>Hello world».

La llibreria necessària per controlar la pantalla LCD s'anomena «LiquidCrystal» i podeu consultar la referència a l'enllaç <https://www.arduino.cc/en/Reference/LiquidCrystal>

```Arduino

Codi: ARD_11.ino

#include <LiquidCrystal.h>  // inclou el codi de la biblioteca

// inicialitza la biblioteca associant qualsevol pin d'interfície LCD necessari al número de pin arduino al qual estigui connectat

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{

  lcd.begin(16, 2);  // configura el nombre de columnes i files de la pantalla LCD
  lcd.print("hello, world!");  // Escriu un missatge a la pantalla LCD

}

void loop()
{

  lcd.setCursor(0, 1);  // posiciona el cursor a la columna 0, línia 1 (Nota: la línia 1 és la segona fila, ja que el recompte comença per 0)
  lcd.print(millis() / 1000);  // imprimeix el nombre de segons des del reinici

}
```

## Definint els teus propis caràcters

Definirem un caràcter propi, el símbol de graus centígrads, per exemple.

El primer que heu de saber, és que els caràcters es defineixen amb un array de 8×8, com si els dibuixàreu en una quadricula d'aqueixa grandària, i emplenant el quadradet pertinent.

Així per exemple per al símbol del grau seria:

![figura-grau](../imatges/ard/ard_11_04.png)

Abans del setup(), en les declaracions i definicions es on creem els caràcters personals.

```Arduino

byte grado[8] =
{
  0b00001100, // _Els definim com binaris_ 0bxxxxxxx
  0b00010010,
  0b00010010,
  0b00001100,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
};
```

Per a muntar els caràcters definits usem:

```Arduino

lcd.createChar(0, euro);
lcd.createChar(1, grau);
```

I ara ja estan disponibles. Tingueu en compte que només podem definir 8 caràcters especials en un moment donat

Aquí tenim un exemple de codi:

```Arduino

#include <LiquidCrystal.h>
LiquidCrystal lcd(_12_, _11_, _5_, _4_, _3_, _2_);

byte grado[8] =
{
  0b00001100,
  0b00010010,
  0b00010010,
  0b00001100,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
};

void setup()

{
  lcd.begin(16, 2); // inicialitzar el LCD
  lcd.createChar(1, grado); // crea el caràcter grado
  lcd.setCursor(0, 0); // posiciona el cursor
  lcd.print("Estamos a 25 "); // missatge
  lcd.write(1); // escritura del caràcter persona
}

void loop()

{

}
```

## Conceptes importants

- Conèixer les pantalles LCD
- Comprendre la connexió amb arduino
- Aprendre a crear els nostres propis caràcters.

## Veure també

- [Index](../Index.md)
- [README](../README.md)
