# 12 - El mòdul de polsador

## Finalitat

- Com utilitzar els polsadors

## Material

|                                 Imatge                                 | Descripció                                                           |
| :--------------------------------------------------------------------: | :------------------------------------------------------------------- |
|   <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">    | Arduino Uno o compatible amb S4A i amb el firmware per S4A carregat. |
| <img src="./../imatges/mat/mat_protoboard.png" width="50" height="50"> | Una protoboard                                                       |
|   <img src="./../imatges/mat/mat_cables.png" width="50" height="50">   | Cables de connexió                                                   |
|   <img src="./../imatges/mat/mat_KY-004.png" width="50" height="50">   | Un mòdul polsador (KY-004)                                           |

## Descripció del material

**Polsadors**

Els commutadors són components realment simples. Quan premeu un botó o gireu una palanca, es connecten dos contactes junts perquè l’electricitat puga circular per ells. Un _polsador_ és un commutador que retorna a la posició de repòs quan deixem d’actuar sobre ell.

Els petits interruptors tàctils que s’utilitzen en aquesta lliçó tenen quatre connexions, que poden ser una mica confós.

![Polsador i esquema](../imatges/ard/ard_12_01.png)

En realitat, només hi ha realment dues connexions elèctriques, ja que a l'interior del paquet d'interruptors els pins B i C estan connectats junts, igual que A i D.

**Mòdul polsador**

Una resistència de 10 K ohm incorporada està connectada entre el pin central i el pin "S" i es pot utilitzar com a resistència de pull-up o pull-down. El polsador connecta els dos pins externs.

![Mòdul polsador](../imatges/ard/ard_12_02.png)

## Muntatge

Anem a fer que el led integrat en la placa arduino i connectat al pin 13 parpellege quan polsem el botó. Per aconseguir-ho cal cablejar la «output» del mòdul al pin 3 de arduino, la Vcc amb 5V i Gnd amb Gnd. Com veieu el muntatge és molt senzill.

![Esquema elèctric](../imatges/ard/ard_12_03.png)
![Muntatge](../imatges/ard/ard_12_04.png)

## Programació

```Arduino

/*
CARTROTECH (www.qode66.xyz)
Projecte nº: ARD012
Data: 29.08.2021
Descripcio: Llegir un polsador i fer parpellejar el led del pin 13
*/

int Led = 13; //Assigna el pin Led
int pols = 3; //Assigna el pin al polsador
int val; //Defineix una variable

void setup()
{
    pinMode(Led, OUTPUT); //Configura el pin 13 (Led) com eixida
    pinMode(pols, INPUT); //Configura el pin 3 (pols) com entrada
}

void loop()
{
    val = digitalRead(pols); //llig el valor de l'entrada 3 i l'assigna a val
    if (val == HIGH)
    {
        digitalWrite (Led,LOW);
    }
    else
    {
        digitalWrite (Led,HIGH);
        delay(200);
        digitalWrite (Led,LOW);
        delay(200);
    }
}
```

## Conceptes importants

- Continuem utilitzant les resistències pull-up o pull-down quan usem polsadors
- Hem aprofitat part del codi del blinking led en aquest programa.

## Veure també

- [Index](../Index.md)
- [README](../README.md)
