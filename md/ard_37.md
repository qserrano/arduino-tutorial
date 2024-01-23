# 37 - Mòdul de rellotge en temps real

## Què és un rellotge de temps real RTC?

Un rellotge de temps real (RTC) és un dispositiu electrònic que permet
obtindre mesuraments de temps en les unitats temporals que emprem de
manera quotidiana.

El terme RTC es va crear per a diferenciar aquest tipus de rellotges
dels rellotges electrònics habituals, que simplement mesuren el temps
comptabilitzant polsos d'un senyal, sense existir relació directa amb
unitats temporals. Per contra els RTC són més semblants als rellotges i
calendaris que usem habitualment, i que funcionen amb segons, minuts,
hores, dies, setmanes, mesos i anys.

Els RTC normalment estan formats per un ressonador de cristall integrat
amb l'electrònica necessària per a comptabilitzar de manera correcta el
pas del temps. L'electrònica dels RTC tenen en compte les peculiaritats
de la nostra manera de mesurar el temps, com per exemple el sistema
sexagesimal, els mesos amb diferents dies, o els anys de traspàs.

Els RTC aporten l'avantatge de reduir el consum d'energia, aportar
major precisió i alliberar a Arduino d'haver de realitzar la
comptabilització del temps. A més, sovint els RTC incorporen algun tipus
de bateria que permet mantindre el valor del temps en cas de pèrdua
d'alimentació.

En el món de l'electrònica casolana i Arduino existeixen dues RTC
habituals el DS1307 i el DS3231, tots dos fabricats per Maxim
(anteriorment Dallas Semiconductor). El DS3231 té una precisió molt
superior i pot considerar-se substitut del DS1307.

En el model DS1307 les variacions de temperatura que afecten el
mesurament del temps dels cristalls ressonadors es tradueixen en errors
en un desfasament acumulat. Això fa que el DS1307 patisca d'un
desfasament temporal, que pot arribar a ser 1 o 2 minuts al dia.

Per a solucionar-ho, el DS3231 incorpora mesurament i compensació de la
temperatura garantint una precisió d'almenys 2ppm, la qual cosa equival
a un desfasament màxim 172ms/dia o un segon cada 6 dies. En el món real
normalment aconsegueixen precisions superiors, equivalent a desfasaments
de 1-2 segons al mes.

![Pins del mòdul](../imatges/ard/ard_37_01.jpeg)

La comunicació en tots dos models es realitza a través del bus I2C, per
la qual cosa és senzill obtindre les dades mesurades. La tensió
d'alimentació és 4.5 a 5.5 per al DS1307, i 2.3 a 5.5V per al DS3231.

Sovint aquests mòduls també incorporen una xicoteta EEPROM AT24C32, que
pot ser emprada per a emmagatzemar registres i mesuraments. En el cas
del DS3231, el mesurament de temperatura també està disponible, encara
que té una precisió baixa ±3 °C, i el temps d'adquisició pot durar fins
a 1 segon.

També incorporen una bateria CR2032 per a mantindre el dispositiu en
hora en retirar l'alimentació. Aquesta bateria hauria de ser capaç de
mantindre alimentat durant diversos anys al DS1307, i durant mesos al
DS3231. La tensió d'alimentació de bateria és de 2.0 a 3.5 per al
DS1307 i de 2.3 a 5.0 per al DS3231.

Els RTC són dispositius àmpliament utilitzats en electrònica. Tots els
ordinadors personals, servidors, tauletes, i telèfon intel·ligent
incorporen un. També són molt freqüents en sistemes embeguts i, en
general, en multitud de dispositius que requereixen realitzar un
registre del temps.

En els nostres projectes d'electrònica sovint necessitàrem un RTC. Per
exemple, podem temporitzar l'encesa de llums o sistemes de reg,
realitzar un datalogger, o fins i tot encendre i apagar el propi Arduino
per a estalvia bateria.

# Material

|                               Imatge                               | Descripció                |
| :----------------------------------------------------------------: | :------------------------ |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent. |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió        |
|  <img src="./../imatges/mat/mat_RTC.png" width="50" height="50">   | Mòdul RTC                 |

## Connexió

![Esquema elèctric](../imatges/ard/ard_37_02.png)
![Cablejat](../imatges/ard/ard_37_03.png)

## Programació

Per fer funcionar el codi de exemple és necessari instal·lar la
biblioteca «DS3231» que podeu trobar en la secció de descàrrega.

```Arduino
/*
* Projecte nº: ARD037
* Data: 09/02/2022
* Descripcio: Prova del modul RTC
* Nota:
*
*/

#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup()
{
    Serial.begin(9600);
    Serial.println("Inicialitza el modul RTC");
    clock.begin();

    // Manual (YYYY, MM, DD, HH, II, SS
    // clock.setDateTime(2016, 12, 9, 11, 46, 00);
    // Envia el temps de compilació d'esbós a Arduino

    clock.setDateTime(__DATE__, __TIME__);

    /*
    Consells: aquesta ordre s'executarà cada cop que es reiniciï Arduino.
    Comenta aquesta línia per emmagatzemar la memòria del mòdul DS3231
    */
}

void loop()
{
    dt = clock.getDateTime();
    Serial.print("Raw data: ");
    Serial.print(dt.year); Serial.print("-");
    Serial.print(dt.month); Serial.print("-");
    Serial.print(dt.day); Serial.print(" ");
    Serial.print(dt.hour); Serial.print(":");
    Serial.print(dt.minute); Serial.print(":");
    Serial.print(dt.second); Serial.println("");

    delay(1000);
}
```

## Altres exemples de codi

Per a realitzar la lectura del DS1307 i del DS3231 usarem la llibreria
desenvolupada per [Adafruit](https://github.com/adafruit/RTClib) vàlida
per a tots dos models, disponible en la secció descàrrega. La llibreria
proporciona exemples de codi, que resulta aconsellable revisar.

### Obtindre la data i hora

El primer exemple empra el RTC per a obtindre les dades de data i hora
actual. Posteriorment s'empren aquests valors per a mostrar-los per
port serie. També es mostra com fixar la data i l'hora, i detectar la
perduda d'energia.

```Arduino
#include <Wire.h>
#include "RTClib.h"

// RTC_DS1307 rtc;
RTC_DS3231 rtc;

String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

void setup()
{
    Serial.begin(9600);
    delay(1000);
    if (!rtc.begin())
    {
        Serial.println(F("Couldn't find RTC"));
        while (1);
    }

    // Si se ha perdido la corriente, fijar fecha y hora
    if (rtc.lostPower())
    {
        // Fijar a fecha y hora de compilacion
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

        // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a
        las 03:00:00
        // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));

    }
}

void printDate(DateTime date)
{
    Serial.print(date.year(), DEC);
    Serial.print('/');
    Serial.print(date.month(), DEC);
    Serial.print('/');
    Serial.print(date.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(date.hour(), DEC);
    Serial.print(':');
    Serial.print(date.minute(), DEC);
    Serial.print(':');
    Serial.print(date.second(), DEC);
    Serial.println();
}

void loop()
{
    // Obtener fecha actual y mostrar por Serial
    DateTime now = rtc.now();
    printDate(now);
    delay(3000);
}
```

## Encesa i apagat programat

El següent exemple un projecte habitual, emprar un RTC per a activar o
desactivar un dispositiu en un horari i dates determinats. Per exemple,
pot servir per a controlar el reg d'un jardí, encendre les llums, la
calefacció, desplegar un tendal, o controlar qualsevol altre dispositiu
mitjançant un relé.

La funció **IsScheduledON** controla l'encesa o apagat. En l'exemple,
està programat l'encesa els dimecres, dissabte, i diumenge de 09.30 a
11.30 i de 21.00 a 23.00. Modificant el cos d'aquesta funció, podeu
programar la condició d'encesa i apagat que necessiteu.

```Arduino

#include <Wire.h>
#include "RTClib.h"

const int outputPin = LED_BUILTIN;
bool state = false;

// RTC_DS1307 rtc;
RTC_DS3231 rtc;

void setup()
{
    Serial.begin(9600);
    delay(1000);
    if (!rtc.begin())
    {
        Serial.println(F("Couldn't find RTC"));
        while (1);
    }
    if (rtc.lostPower())
    {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

// Comprobar si esta programado el encendido
bool isScheduledON(DateTime date)
{
    int weekDay = date.dayOfTheWeek();
    float hours = date.hour() + date.minute() / 60.0;

    // De 09:30 a 11:30 y de 21:00 a 23:00
    bool hourCondition = (hours > 9.50 && hours < 11.50) || (hours > 21.00 && hours < 23.00);

    // Miercoles, Sabado o Domingo
    bool dayCondition = (weekDay == 3 || weekDay == 6 || weekDay == 0);

    if (hourCondition && dayCondition)
    {
        return true;
    }
    return false;
}

void loop()
{
    DateTime now = rtc.now();
    if (state == false && isScheduledON(now)) // Apagado y debería estar encendido
    {
        digitalWrite(outputPin, HIGH);
        state = true;
        Serial.print("Activado");
    }
    else if (state == true && !isScheduledON(now)) // Encendido y deberia estar apagado
    {
        digitalWrite(outputPin, LOW);
        state = false;
        Serial.print("Desactivar");
    }
    delay(3000);
}
```

## Datalogger amb RTC

El següent exemple mostra un altre cas molt habitual, l'ús d'un RTC
per a generar un **Datalogger**, és a dir, un dispositiu que
periòdicament registra el mesurament d'un sensor. En l'exemple, usarem
una targeta SD per a guardar els valors.

Simplement, obtenim la data, hora, i valor del sensor, que en l'exemple
simulem amb la funció **readSensor()**, i guardem les dades en la
targeta amb la funció **logValue(,,)**.

En un projecte real podríem guardar una o diversos mesuraments,
separades per comes, per exemple. També podríem variar el moment del
mesurament, que en l'exemple es realitza cada 10 segons a, per exemple,
quan ocórrega un esdeveniment, o en unes certes hores del dia emprant el
propi RTC.

```Arduino

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

File logFile;
// RTC_DS1307 rtc;
RTC_DS3231 rtc;

void setup()
{
    Serial.begin(9600);
    Serial.print(F("Iniciando SD ..."));
    if (!SD.begin(4))
    {
        Serial.println(F("Error al iniciar"));
        return;
    }
    Serial.println(F("Iniciado correctamente"));
}

// Funcion que simula la lectura de un sensor
int readSensor()
{
    return 0;
}

void logValue(DateTime date, int value)
{
    logFile.print(date.year(), DEC);
    logFile.print('/');
    logFile.print(date.month(), DEC);
    logFile.print('/');
    logFile.print(date.day(), DEC);
    logFile.print(" ");
    logFile.print(date.hour(), DEC);
    logFile.print(':');
    logFile.print(date.minute(), DEC);
    logFile.print(':');
    logFile.print(date.second(), DEC);
    logFile.print(" ");
    logFile.println(value);
}

void loop()
{
    // Abrir archivo y escribir valor
    logFile = SD.open("datalog.txt", FILE_WRITE);

    if (logFile)
    {
        int value = readSensor();
        DateTime now = rtc.now();
        logValue(now, value);
        logFile.close();
    }
    else
    {
        Serial.println(F("Error al abrir el archivo"));
    }
    delay(10000);
}

```

## Descàrrega

- [Codi ARD037](https://mega.nz/folder/ee4UharQ#wf_KDJsDrr8pQQlBTt8TEA)
- [Fritzing part Real Time Clock Module - DS1307 RTC Breakout Board](https://mega.nz/file/mDhG3YzR#SxeFgBbHX91ffjRCZkSOqI1vkHtydJynLVofyOY31Bs)
- [Llibreria DS3231.zip](https://mega.nz/file/nehSTYTC#D3vGWMlD7JKl5dYlAQXs0UOWuh6Ry2Fk-7mGsqJERfA)
- [Llibreria Adafruit RTClib](https://mega.nz/file/WXgwDAKZ#SCBhuhfib79dAgiHLheFRjpoQD3xmajfFhTInhglVHM)

## Veure també

- [Index](../Index.md)
- [README](../README.md)
