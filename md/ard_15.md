# 15 - Mòdul de brunzidor passiu

## Finalitat

- Aprendre a utilitzar el brunzidor
- Incloure avisos sonors en els nostres circuits

## Material

|                               Imatge                               | Descripció                 |
| :----------------------------------------------------------------: | :------------------------- |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent.  |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió         |
| <img src="./../imatges/mat/mat_KY-006.png" width="50" height="50"> | Un brunzidor passiu KY-006 |

## Descripció

### Què és?

Un brunzidor és un transductor electroacústic que produeix un so continu
o intermitent d'un mateix to, generalment agut. El brunzidor transforma
el senyal elèctric que rep en una vibració, que genera un soroll. Com
més alta és el senyal que rep, més intensa és la vibració i més fort és
el so.

### Especificacions

El mòdul de brunzidor passiu (KY-006) pot generar tons entre 1.5 a 2.5
kHz en encendre-ho i apagar-ho en diferents freqüències usant retards o
PWM.

| Característica            | Valor           |
| ------------------------- | --------------- |
| Voltatge de funcionament  | 1,5 ~ 15 V CC   |
| Rang de generació de tons | 1,5 ~ 2,5 kHz   |
| Dimensions                | 18,5 mm x 15 mm |

### Cóm funciona?

El funcionament es basa en l'efecte piezoelèctric dels materials,
Aquest efecte funciona de tal manera que quan apliquem un voltatge el
volum del material canvia lleugerament. Els brunzidors estan construïts
amb dues xicotetes plaques una metàl·lica i una ceràmica, les quals
aprofiten aquest efecte però només generen un clic ja que els materials
van canviar de forma però no tornen al seu estat natural fins que se'ls
lleva el voltatge.

![Efecte piezoelèctric](../imatges/ard/ard_15_01.png)

Perquè es puga emetre un so continu les plaques necessiten vibrar
constantment, per a això es necessita un oscil·lador que fa que els
materials canvien d'estat una vegada i una altra, i així puguen canviar
milers de vegades per a poder aconseguir un àudio perceptible.

En aquest cas ho aconseguirem canviant el estat d'una eixida digital de
la placa arduino. Recordem que el so és audible des de 20 Hz fins al 20
kHz, per tant, el nombre de vegades que la eixida deu canviar (anomenat
freqüència) estarà entre les 20 i les 20000 vegades per segon.

![Muntatge del brunzidor](../imatges/ard/ard_15_02.png)
![Esquema elèctric](../imatges/ard/ard_15_03.png)

El muntatge ho farem directament amb cables tipus Dupont M-F, connectant
la eixida 8 amb la S (senyal) del brunzidor i per altra banda el pin GND
de la placa amb el pin « -- « del mòdul.

![Muntatge final](../imatges/ard/ard_15_04.png)

## Programació

Codi: ARD_15

```Arduino

int buzzer = 8; // estableix el pin digital de control del buzzer

void setup()
{
  pinMode(buzzer, OUTPUT); // configura el pin 8 com eixida
}

void loop()
{
  for (int i = 0; i < 80; i++) // crea un so de 500 Hz
  {
    digitalWrite(buzzer, HIGH); // envia senyal alta al buzzer
    delay(1); // delay 1ms
    digitalWrite(buzzer, LOW); // envia senyal baixa al buzzer
    delay(1);
  }
  delay(50);

  for (int j = 0; j < 100; j++)  //crea un so de 250 HZ
  {
    digitalWrite(buzzer, HIGH);
    delay(2); // delay 2ms
    digitalWrite(buzzer, LOW);
    delay(2);
  }
delay(100);
}
```

## Conceptes importants

- Efectes dels activadors acústics
- Entendre què és la freqüència

## Veure també

- [Index](../Index.md)
- [README](../README.md)
