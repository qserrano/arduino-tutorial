# 21 - Mòduls de detecció de so

## Visió general

En aquest experiment, aprendrem a utilitzar el sensor de veu d'alta
sensibilitat. Hi han dos tipus: el mòdul de micròfon gran i el mòdul de
micròfon xicotet.

## Material

|                               Imatge                               | Descripció                      |
| :----------------------------------------------------------------: | :------------------------------ |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.       |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió              |
| <img src="./../imatges/mat/mat_KY-037.png" width="50" height="50"> | Mòdul micròfon gran (KY-037)    |
| <img src="./../imatges/mat/mat_KY-038.png" width="50" height="50"> | Mòdul micròfon xocotet (KY-038) |

## Mòdul de micròfon gran

Un mòdul de micròfon amb una càpsula d'electret de gran format d'alta
sensibilitat.

És un mòdul de detecció de so que té dos pins de senyal d'eixida. un
pin digital (D0), quan detecta algun so fins a un cert llindar, pot
emetre un nivell alt o baix. Un pin analògic (A0), pot donar en temps
real la senyal de voltatge d'eixida del micròfon.

Un potenciòmetre permet ajustar el nivell.

![Mòdul micròfon KY-037](../imatges/ard/ard_21_01.png)

## Mòdul de micròfon xicotet

Un mòdul de micròfon amb una xicoteta càpsula electret.

L'eixida "DO" (activa alta) es canvia quan el nivell de so excedeix
un nivell preestablit. Un potenciòmetre permet ajustar el nivell.

Excepte per la grandària més xicoteta de la càpsula i la seua menor
sensibilitat, el mòdul és idèntic al mòdul "Micròfon gran"

![Mòdul micròfon KY-038](../imatges/ard/ard_21_02.png)

## Sensor de so

El mòdul del sensor de so proporciona una manera fàcil de detectar el so
i generalment s'usa per a detectar la intensitat del so. Aquest mòdul
es pot utilitzar per a aplicacions de seguretat, commutació i
supervisió. La seua precisió es pot ajustar fàcilment per a la
conveniència d'ús.

Utilitza un micròfon que subministra l'entrada a un amplificador,
detector de pics i búfer.

Quan el sensor detecta un so, proporciona un voltatge de senyal
d'eixida que s'envia a un microcontrolador que realitza el
processament necessari.

![Sensor de so](../imatges/ard/ard_21_03.png)

Aquests micròfons s'utilitzen àmpliament en circuits electrònics per a
detectar sons menors o vibracions de l'aire que al seu torn es
converteixen en senyals elèctrics per al seu ús posterior. Les dues
potes, com es mostra en la imatge de dalt, s'utilitzen per a realitzar
la connexió elèctrica amb el circuit.

![Coberta del sensor de so](../imatges/ard/ard_21_04.png)

Un cos de metall conductor sòlid encapsula les diferents parts del
micròfon. La cara superior es cobreix amb un material porós amb l'ajuda
de cola. Actua com a filtre de les partícules de pols. Els senyals de so/vibracions de l'aire passen a través del material porós i cauen sobre
el diafragma a través de l'orifici que es mostra en la imatge de dalt.

## Connexionat

Es mostra el cablejat per al mòdul de micròfon gran, però es idèntic si
utilitzem el mòdul de micròfon xicotet.

![Connexionat mòdul de micròfon](../imatges/ard/ard_21_05.png)

## Programació

```Arduino
/*
* Projecte nº: **ARD021**
* Data: 06.11.2021
* Descripcio: Modul deteccio so
* Nota:
*
*/

int sensorAnalogPin = A0;
int sensorDigitalPin = 7;
int analogValue = 0;
int digitalValue;
int Led = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorDigitalPin,INPUT);
  pinMode(Led,OUTPUT);
}

void loop()
{
  analogValue = analogRead(sensorAnalogPin);
  digitalValue=digitalRead(sensorDigitalPin);
  Serial.println(analogValue);
  if(digitalValue==HIGH)
  {
    digitalWrite(Led,HIGH);
  }
  else
  {
    digitalWrite(Led,LOW);
  }
  delay(50); // Pausa per a no sobrecarregar la interfície serie
}
```

## Veure també

- [Index](../Index.md)
- [README](../README.md)
