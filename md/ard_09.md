# 09 - Sensor de cop i de vibració

## Finalitat

Presentar el sensor de cop i de vibració (KY-002 i KY-031), a més de continuar treballant les entrades digitals per saber detectar senyals molt breus.

## Material

|                                 Imatge                                 | Descripció                                                           |
| :--------------------------------------------------------------------: | :------------------------------------------------------------------- |
|   <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">    | Arduino Uno o compatible amb S4A i amb el firmware per S4A carregat. |
| <img src="./../imatges/mat/mat_protoboard.png" width="50" height="50"> | Una protoboard                                                       |
|   <img src="./../imatges/mat/mat_cables.png" width="50" height="50">   | Cables de connexió                                                   |
|   <img src="./../imatges/mat/mat_KY-002.png" width="50" height="50">   | Un mòdul KY-002, sensor de cop                                       |
|   <img src="./../imatges/mat/mat_KY-031.png" width="50" height="50">   | Un mòdul KY-031, detector de vibració                                |

## ¿Cóm funcionen els mòduls?

El mòdul del conmutador de vibració KY-002 (vibration switch module) exteriorment presenta una forma cilíndrica. Les dues parts actives a l'interior del sensor són un moll conductor al centre envoltat per una placa també conductora. Aquesta configuració fa que quan s'aplica
qualsevol tipus de xoc al mòdul, la molla entra en contacte amb la coberta cilíndrica i el circuit es tanca.

El mòdul sensor de cop KY-031 és similar al mòdul de vibració. La diferència principal entre aquests dos és la seva sensibilitat. El sensor de vibració detecta fins i tot un xoc petit, mentre que el sensor de cops requereix un cop potent o una sacsejada per activar-lo.

Els dos mòduls porten una resistència de 10 K Ohm incorporada entre el pin central i el pin "S" per a ser usat com a muntatge **pull up o pull down** segons es requerisca. Els contactes de l'interruptor connecten els dos pins externs.

Tots dos mòduls canvien l'estat del connector de eixida quan detecten el cop o vibració i el mantenen únicament mentre dura la pertorbació, és a dir, s'obté una senyal d'una durada molt breu. Si fem el muntatge habitual tindrem una configuració pull up, la eixida estarà a l'estat alt fins que el sensor s'active que passarà a estat baix.

## Muntatge

L'esquema electrònic és molt senzill, com que tenim una senyal digital l'arreplegarem per l'entrada 2 i aprofitarem el led de la placa arduino, connectat al pin 13 per veure la eixida.

![Esquema-electronic](../imatges/ard/ard_09_01.png)
![esquema-muntatge](../imatges/ard/ard_09_02.png)

## Programació

[Codi:ARD_09.ino](../codi/ARD_09.ino)

```Arduino

int Led = 13; //assigna a la variable Led el valor de 13

int buttonpin = 2; //assigna a la variable buttonpin el valor 2

int val; //defineix val com enter

void setup()
{
  pinMode(Led, OUTPUT); //defineix el pin 13 com eixida
  pinMode(buttonpin, INPUT); //defineix el pin 2 com entrada digital
}

void loop()
{
  val = digitalRead(buttonpin); //llig el valor de l'entrada 2 i l'assigna a la variable val
  if (val == HIGH) //comproba si el sensor s'activat, recordeu que si detecta l'entrada 2 passara a estat baix
  {
    digitalWrite(Led, LOW);
  }

else //quan el sensor envia senyal, el led 13 //s'encen durant 2 segons
  {
    digitalWrite(Led, HIGH);
    delay(2000);
  }
}
```

## Conceptes importants

- Detecció de senyals molt breus
- Muntatge pull-up i pull-down

## Veure també

- [Index](../Index.md)
- [README](../README.md)
