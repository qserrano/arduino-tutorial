# 16 -- Mòdul làser

## Objectiu

En aquest experiment, aprendrem a utilitzar el mòdul làser.

## Material

|                               Imatge                               | Descripció                |
| :----------------------------------------------------------------: | :------------------------ |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent. |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió        |
| <img src="./../imatges/mat/mat_KY-008.png" width="50" height="50"> | Un mòdul laser KY-008     |

## Descripció

El mòdul transmissor làser, 650 nm (roig), emet un feix xicotet i
intens. Encara que aquest mòdul és segur per al seu projecte, no mire
directament al raig.

**Advertiment**: aquest làser de classe 3B pot causar lesions oculars, evite
expossar-se al raig.

![Mòdul làser](../imatges/ard/ard_16_01.png)

Especificacions:

- Voltatge de funcionament: 5 V
- Longitud d'ona: 650 nm Color de la llum: roja
- Grandària: 27 x 15 mm
- Tipus: Classe 3B

## Què és i cóm funciona un làser

![Parts i funcionament del làser](../imatges/ard/ard_16_02.png)

## Els components del làser

Un làser té tres parts bàsiques:

1. Una càrrega d'àtoms (un sòlid, líquid o gas) amb electrons a estimular al voltant del nucli, com hem vist. Això es coneix com el **medi làser** o, a vegades, el **mitjà d'amplificació** o «guany» (perquè "guany" és una altra manera de referir-se a l'amplificació).
2. Una cosa amb la qual estimular els àtoms, com un tub de flaix (com
   el llum de flaix de xenó en una càmera) o un altre làser. Això es
   denomina **sistema de bombeig**.
3. Una cavitat òptica o **ressonador.**

## Cóm funciona un làser

1. Un subministrament elèctric fa que una font d'alimentació lluminosa
   s'encenga i apague intermitentment.
2. Cada vegada que la llum parpelleja, «bomba» energia al medi làser.
   Els flaixos fan que s'injecte energia en el cristall de robí en
   forma de fotons.
3. Els àtoms en el medi absorbeixen aquesta energia en un procés
   anomenat absorció. Els àtoms absorbeixen energia quan els seus
   electrons salten a un nivell d'energia més alt (cercles amb creu),
   com hem vist anteriorment. Després d'uns pocs mil·lisegons, els
   electrons tornen al seu nivell d'energia original (estat
   fonamental) emetent un fotó de llum (fletxes ondulades). Això es diu
   emissió espontània.
4. Els fotons emesos pels àtoms s'acosten i allunyen dins del cristall
   de robí, viatjant a la velocitat de la llum.
5. En alguns moments, un d'aquests fotons estimula un àtom ja excitat.
   Quan això succeeix, l'àtom excitat emet un fotó i recuperem també
   el nostre fotó original. Això es diu emissió estimulada. En aqueix
   moment, un fotó de llum ha produït dos fotons de llum, així que
   aquesta s'ha amplificat (augmentat en força). En altres paraules,
   l'«amplificació de llum» (un augment en la quantitat de llum) ha
   sigut causada per «emissió estimulada de radiació». D'ací el nom
   "làser" (_acrònim anglès de Light Amplification by Stimulated
   Emission of Radiation «amplificació de llum per emissió estimulada
   de radiació»)_.
6. Un espill en un extrem del tub làser manté els fotons rebotant cap
   avant i cap endarrere dins del cristall.
7. Un espill parcial en l'altre extrem del tub fa rebotar alguns
   fotons en el cristall, però deixa escapar a alguns.
8. Els fotons que escapen formen un feix molt concentrat llum làser
   molt potent, que és el que s'usa, per exemple, per a tallar un tub
   metàl·lic.

Però tots aquests processos i components estan dins del xicotet
encapsulat del mòdul, per tant l'única cosa que nosaltres veurem serà el
raig de llum.

## Muntatge

En primer lloc farem que el làser s'encenga i s'apague alternativament,
després un nou codi ens permetrà variar la intensitat del làser.

![Diagrama de muntatge mòdul làser](../imatges/ard/ard_16_03.png)
![Esquema elèctric mòdul làser](../imatges/ard/ard_16_04.png)

## Programació

Aquí teniu dos programes molt senzills per provar aquest sensor, que
podeu descarregar aquí:
[ARD_16a.ino](https://drive.google.com/file/d/1pCOO_AEN38eGd4omei5IUisHmrGPqtZt/view?usp=share_link),
[ARD_16b.ino](https://drive.google.com/file/d/1YsyZ0doSccj-J1inmuhwv7s9aYoz8JwE/view?usp=share_link)

**Codi: ARD_16a**

```Arduino

void setup ()
{
    pinMode (_9_, OUTPUT); // defineix el pin _9_ com eixida digital
}

void loop ()
{
    digitalWrite (_9_, HIGH); // _activa el laser_
    delay (1000); // _espera 1 seg_
    digitalWrite (_9_, LOW); // _apaga el laser_
    delay (1000); // _espera 1 seg_
}
```

**Codi: ARD_16b**

```Arduino

int laser = 0; //defineix la variable laser

void setup()
{
    pinMode(9,OUTPUT); //configura el pin 9 com eixida
}

void loop()
{
    for (laser = 0; laser <= 255; laser += 1)
    {
        analogWrite(9,laser); //escriu en el pin 9 el valor de laser
        delay(5); //espera 5 mil·lisegons
    }
    for (laser = 255; laser >= 0; laser -= 1)
    {
        analogWrite(9,laser);
        delay(5);
    }
}
```

## Conclusió

- Sabem com funciona un làser i com està construït
- Hem conegut el mòdul làser (KY-008)
- Veiem que podem regular la intensitat del raig

## Veure també

- [Index](../Index.md)
- [README](../README.md)
