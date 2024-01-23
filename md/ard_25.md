# 25 - Mòdul sensor de flama

## Descripció general

En aquest experiment, aprendrem a usar el mòdul sensor de flama.

Aquest mòdul és sensible a la flama ja la radiació. També pot detectar
fonts de llum ordinàries en el rang de longitud d'ona de 760nm-1100nm.
La distància de detecció és de fins a 100 cm.

El sensor de flama pot emetre un senyal digital o analògic. Es pot
utilitzar com a alarma de flama o en robots d'extinció d'incendis.

## Mòdul sensor de flama

Un mòdul sensor per a detectar flames. La sensibilitat espectral del
sensor està optimitzada per a detectar emissions de flames visibles. El
senyal d'eixida 'DO' s'eleva (HIGH) quan es detecta una flama. El
llindar de commutació es pot ajustar a través d'un potenciòmetre
preestablit. Un senyal d'eixida analògica del sensor està disponible en
el pin 'AO'.

- Sensibilitat espectral típica: 720-1100 nm
- Angle de detecció típic: 60°

![Pins del mòdul KY-026](../imatges/ard/ard_25_01.png)

# Material

|                               Imatge                               | Descripció                  |
| :----------------------------------------------------------------: | :-------------------------- |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.   |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió          |
| <img src="./../imatges/mat/mat_KY-026.png" width="50" height="50"> | Mòdul sensor de flama KY026 |

## Especificacions

Mòdul sensor de flama:

- Detecta una flama o una font de llum d'una longitud d'ona en el
  rang de 760nm-1100nm
- Distància de detecció: 20 cm (4,8 V) \~ 100 cm (1 V)
- Angle de detecció d'uns 60 graus, és sensible a l'espectre de la
  flama.
- El xip comparador LM393 fa que les lectures del mòdul siguen
  estables.
- Rang de detecció ajustable.
- Voltatge de funcionament 3,3 V-5 V
- Eixides digitals DO de commutació (0 i 1) i AO eixida de tensió
  analògica
- Indicador d'alimentació i indicador d'eixida d'interruptor
  digital

## Connexions

![Muntatge KY-026](../imatges/ard/ard_25_02.png)
![Esquema elèctric KY-026](../imatges/ard/ard_25_03.png)

## Codi

### Ús de la eixida digital del sensor (DO)

![Ús eixida digital](../imatges/ard/ard_25_04.png)

```Arduino
/*
* Projecte nº: ARD025a
* Data: 16/01/2022
* Descripcio: Activa led si detecta flama
* Nota: Ús eixida digital
*
*/

int Led = 13; //define LED port
int buttonpin = 3; //define switch port
int val; //define digital variable val

void setup()
{
    pinMode(Led, OUTPUT); //define LED as a output port
    pinMode(buttonpin, INPUT); //define switch as a output port
}

void loop()
{
    val = digitalRead(buttonpin);
    if (val == HIGH) //when the switch sensor have signal, LED blink
    {
        digitalWrite(Led, HIGH);
    }
    else
    {
        digitalWrite(Led, LOW);
    }
}
```

### Ús de la eixida analògica del sensor (AO)

![Ús eixida analògica](../imatges/ard/ard_25_05.png)

```Arduino
/*
* Projecte nº: ARD025b
* Data: 16/01/2022
* Descripcio: Llig valor analogic del sensor
* Nota:
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

## Veure també

- [Index](../Index.md)
- [README](../README.md)
