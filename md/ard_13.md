# 13 - Mòduls Transmisor i Receptor IR

## Finalitat

En aquest experiment, aprendrem a utilitzar el mòdul transmissor
d'infrarojos i el receptor d'infrarojos.
De fet, en la nostra vida quotidiana juguen un paper important en la
majoria dels electrodomèstics que s’utilitzen a aquest tipus de
dispositius, com ara aire condicionat, TV, DVD, etc. En realitat es basa
en la seua teledetecció sense fils i és molt convenient utilitzar-los.

## Material

|                               Imatge                               | Descripció                                                           |
| :----------------------------------------------------------------: | :------------------------------------------------------------------- |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o compatible amb S4A i amb el firmware per S4A carregat. |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió                                                   |
| <img src="./../imatges/mat/mat_KY-022.png" width="50" height="50"> | Mòdul receptor IR KY022                                              |
| <img src="./../imatges/mat/mat_KY-005.png" width="50" height="50"> | Mòdul emissor IR KY005                                               |

## Descripció del material

### Receptor IR

Sensor d'infrarojos tipus 1838 per a ús amb senyals IR de 38 KHz.

- Tensió d’alimentació: 2,7 a 5,5 V
- Freqüència: 37,9 KHz
- Abast del receptor: 18 m (típic)
- Angle de recepció: 90 °

![Receptor IR](../imatges/ard/ard_13_01.png)

Els detectors IR són petits microxips amb fotocèl·lula que s’ajusten per
escoltar la llum infraroja. Gairebé sempre s’utilitzen per a la detecció
de control remot: cada reproductor de TV i DVD en té un a la part
frontal per llegir el senyal IR des del comandament. A l'interior del
comandament a distància hi ha un LED IR coincident, que emet impulsos IR
per dir al televisor que s'encenga, s'apague o canvie de canal. La llum
IR no és visible a l’ull humà, de manera que es necessita una mica més
de treball per provar una configuració.

Els detectors IR es filtren especialment per a la llum infraroja, no són
bons per detectar la llum visible. D’altra banda, les fotocèl·lules són
bones per detectar la llum visible de color groc/verd, no són bones
per a la llum IR.

- Els detectors IR tenen un desmodulador a l’interior que busca IR
  modulats a 38 kHz. No es detectarà la brillantor d’un LED d’IR, sinó que
  haurà de parpellejar a 38 kHz. Les fotocèl·lules no tenen cap classe de
  desmodulador i poden detectar qualsevol freqüència (inclosa la CC) dins
  de la velocitat de resposta de la fotocèl·lula (que és d’uns 1 kHz).
- Els detectors IR són de sortida digital: si detecten un senyal IR de
  38 kHz, donen una sortida baixa (0V) o si bé no en detecten cap,
  produeixen una sortida alta (5V). Les fotocèl·lules actuen com a
  resistències, la resistència canvia en funció de la quantitat de llum a
  què estan exposades.

### Transmissor IR

Aquest mòdul s’utilitza generalment juntament amb el mòdul de receptor
IR, les aplicacions d’aquest mòdul són molt àmplies en la nostra vida
comuna. L'IR-LED es pot utilitzar per construir una barrera de llum o un
transmissor de senyal de control remot IR.

Aquest mòdul és igual que un LED, però el color de la llum no es pot
veure a l’ull humà, sinó que podeu veure la llum a través de la càmera
del telèfon.

![Emissor IR](../imatges/ard/ard_13_02.png)

## Muntatge

Aquest muntatge és molt senzill, no ens fa falta protoboard però en
canvi necessitem dues plaques arduino.

Els cables d’alimentació (5V i GND) tenen posicions fixes en la placa,
els cables de dades els conectarem en la entrada/eixida corresponent
segons indiquem en el codi

![Muntatge receptor](../imatges/ard/ard_13_03.png)
![Muntatge emissor](../imatges/ard/ard_13_05.png)

---

![Esquema elèctric receptor](../imatges/ard/ard_13_04.png)
![Esquema elèctric emissor](../imatges/ard/ard_13_06.png)

## Programació

Codi: ARD_13_IRe (pujar a la placa del emissor)

```Arduino

#include <IRremote.h>

IRsend irsend;

void setup()
{

}

void loop()
{
    digitalWrite(13,LOW);
    irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
    delay(200);
    digitalWrite(13,HIGH);
    irsend.sendRC5(0x1, 8);
    delay(200);
}

```

Codi: ARD_13_IRr (pujar a la placa del receptor)

```Arduino

#include <IRremote.h>
#define RECV_PIN 11 //Pin de recepcio del senyal IR
#define LED 13 //defineix LED pin

IRrecv irrecv(RECV_PIN); //crear l'objecte irrecv per al receptor IR en el pin indicat

decode_results results; //declarem la variable results (dades de la recepcio)

void setup()
{
    pinMode(LED, OUTPUT); //inicialitza LED com eixida
    Serial.begin(9600);
    irrecv.enableIRIn(); //activa l'objecte irrecv
}

void loop()
{
    if (irrecv.decode(&results)) //comprovem si arriven dades
    {
        int state;
        if ( results.value ## 1 )
        {
            state # HIGH;
        }
        else
        {
            state # LOW;
        }
    digitalWrite( LED, state );
    Serial.println(results.value);
    irrecv.resume(); // comencem una nova recepció
    }
}

```

## Conceptes importants

- Com funcionen el transmissor i el receptor de infrarojos.

## Veure també

- [Index](../Index.md)
- [README](../README.md)
