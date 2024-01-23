# 34 -- Mòdul GY-521

## Descripció general

En aquesta lliçó, aprendrem a usar el mòdul GY-521 (MPU-6050), que és un
dels millors sensors de mesurament d'inèrcia IMU (Inertia Measurement
Unit), compatible amb Arduino.

Els sensors IMU com el GY-521 (MPU-6050) s'utilitzen en robots
auto-equilibrats, vehicles aeris no tripulats, telèfons intel·ligents,
etc.

![Pins del mòdul GY-521](../imatges/ard/ard_34_01.jpeg)

## Material

|                               Imatge                               | Descripció                |
| :----------------------------------------------------------------: | :------------------------ |
| <img src="./../imatges/mat/mat_unor3.png" width="50" height="50">  | Arduino Uno o equivalent. |
| <img src="./../imatges/mat/mat_cables.png" width="50" height="50"> | Cables de connexió        |
| <img src="./../imatges/mat/mat_GY-521.png" width="50" height="50"> | Mòdul GY-521              |

## Introducció de components

### Sensor GY-521

El sensor InvenSense GY-521 conté un acceleròmetre MEMS i un giroscopi
MEMS en un sol xip (MEMS = MicroElectroMechanic System). És molt precís,
ja que conté maquinari de conversió d'analògic a digital de 16 bits per
a cada canal. Per tant, captura el canal x, y i z al mateix temps. El
sensor utilitza el bus I2C per a interactuar amb l'Arduino.

El GY-521 no és car, especialment atés que combina un acceleròmetre i un
giroscopi.

Els sensors IMU són un dels tipus de sensors més inevitables que
s'utilitzen hui dia en tota mena de dispositius electrònics.

Es veuen en telèfons intel·ligents, dispositius portàtils, controladors
de jocs, etc. Els sensors IMU ens ajuden a obtindre la posició d'un
objecte adjunt al sensor en un espai tridimensional. Aquests valors
solen estar en angles, la qual cosa ens ajuda a determinar la seua
posició. Per tant, s'utilitzen en telèfons intel·ligents per a detectar
la seua orientació. I també, en dispositius portàtils com la «fit band»,
que usen sensors IMU per a rastrejar el moviment.

### Com funciona?

Els sensors IMU generalment consten de dos o més parts. Enumerant-los
per prioritat, són: **acceleròmetre, giroscopi, magnetòmetre i altímetre.** El GY-521 és un sensor IMU de 6 graus de llibertat (DOF =
Degrees Of Freedom) o de sis eixos, cosa que significa que dona sis
valors com a eixida. Tres valors de l'acceleròmetre i tres del
giroscopi. El GY-521 és un sensor basat en tecnologia MEMS (Micro
Electro Mechanical Systems). Tant l'acceleròmetre com el giroscopi
estan integrats dins d'un sol xip. Aquest xip utilitza el protocol I2C
(Inter Integrated Circuit) per a la comunicació.

### Com funciona un acceleròmetre?

![Funcionament d'un acceleròmetre](../imatges/ard/ard_34_02.png)

Un acceleròmetre funciona segons el principi de l'efecte piezoelèctric.
Ací, imagina una caixa amb forma de cub, amb una xicoteta bola dins, com
en la imatge de dalt. Les parets d'aquesta caixa estan fetes amb
cristalls piezoelèctrics.

Cada vegada que inclines la caixa, la bola es veu obligada a moure's en
la direcció de la inclinació, a causa de la gravetat.

La paret amb la qual xoca la bola crea xicotets corrents piezoelèctrics.
Hi ha en total, tres parells de parets oposades en un paral·lelepípede.
Cada parell correspon a un eix en l'espai 3D: eixos X, Y i Z. Depenent
del corrent produït per les parets piezoelèctriques, podem determinar
l'adreça d'inclinació i la seua magnitud.

![Eixos espacials](../imatges/ard/ard_34_03.png)

### Com funciona un giroscopi?

Els giroscopis funcionen segons el principi de l'acceleració de
Coriolis. Imagine que hi ha una estructura similar a una forqueta, que
està en constant moviment cap avant i cap endarrere. Es manté en el seu
lloc mitjançant cristalls piezoelèctrics. Cada vegada que intenta
inclinar aquest arranjament, els cristalls experimenten una força en la
direcció de la inclinació. Això es produeix com a resultat de la inèrcia
de la forqueta en moviment.

Els cristalls produeixen així un corrent en consens amb l'efecte
piezoelèctric, i aquest corrent s'amplifica. Després, els valors són
refinats pel microcontrolador.

![Funcionament d'un giroscopi](../imatges/ard/ard_34_04.png)

## Connexió

![Esquema elèctric](../imatges/ard/ard_34_05.png)
![Cablejat](../imatges/ard/ard_34_06.png)

## Programació

Els exemples següents són traducció del article de Luis Llamas
(https://www.luisllamas.es/arduino-orientacion-imu-mpu-6050/).

Per a realitzar la lectura del MPU-6050 usarem la llibreria
desenvolupada per Jeff Rowberg disponible en [aquest
enllaç](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050).
També emprarem [la llibreria
I2Cdev](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/I2Cdev)
desenvolupada pel mateix autor, que millora la comunicació I2C.

La llibreria proporciona exemples de codi, que resulta aconsellable
revisar. Els següents exemples són modificacions a partir dels
disponibles en la llibreria.

### Llegir valors RAW

En el primer exemple, aprenem a llegir els valors directament
proporcionats pel MPU-6050 (valors RAW) a través del bus I2C. Els valors
RAW tenen un rang de mesurament entre -32768 i +32767.

```Arduino

/*
* Projecte nº: ARD034a
* Data: 03/02/2022
* Descripcio: Llegir valors RAW
* Nota: traduït de Luis Llamas
*
*/

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int mpuAddress = 0x68; //Pot ser 0x68 o 0x69

MPU6050 mpu(mpuAddress);

int ax, ay, az;
int gx, gy, gz;

void printTab()
{
    Serial.print(F("t"));
}

void printRAW()
{
    Serial.print(F("a[x y z] g[x y z]:t"));
    Serial.print(ax); printTab();
    Serial.print(ay); printTab();
    Serial.print(az); printTab();
    Serial.print(gx); printTab();
    Serial.print(gy); printTab();
    Serial.println(gz);
}

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();
    Serial.println(mpu.testConnection() ? F("IMU iniciat correctament") : F("Error al iniciar IMU"));
}

void loop()
{
    // Llegir les acceleracions i velocitats angulars
    mpu.getAcceleration(&ax, &ay, &az);
    mpu.getRotation(&gx, &gy, &gz);
    printRAW();
    delay(100);
}

```

### Llegir valors en Sistema Internacional

En el següent exemple apliquem una escala als valors RAW per a obtindre
mesuraments amb significat físic. En l'exemple, emprarem valores G per
a l'acceleració, i º/s per a la velocitat angular. Amb facilitat podreu
modificar el codi perquè proporcione els valors en unitats del Sistema
Internacional. L'escalat dependrà del rang de mesurament que
seleccionem en el MPU-6050, que recordem pot ser 2g/4g/8g/16g per a
l'acceleròmetre i 250/500/1000/2000 (°/s) per al giroscopi.

```Arduino

/*
* Projecte nº: ARD034b
* Data: 03/02/2022
* Descripcio: Llegir valors en SI
* Nota:
*
*/

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int mpuAddress = 0x68; // Pot ser 0x68 o 0x69

MPU6050 mpu(mpuAddress);

int ax, ay, az;
int gx, gy, gz;

// Factors de conversio
const float accScale = 2.0 * 9.81 / 32768.0;
const float gyroScale = 250.0 / 32768.0;

void printTab()
{
    Serial.print(F("t"));
}

// Mostrar mesures en Sistema Internacional
void printRAW()
{
    Serial.print(F("a[x y z](m/s2) g[x y z](deg/s):t"));
    Serial.print(ax * accScale); printTab();
    Serial.print(ay * accScale); printTab();
    Serial.print(az * accScale); printTab();
    Serial.print(gx * gyroScale); printTab();
    Serial.print(gy * gyroScale); printTab();
    Serial.println(gz * gyroScale);
}

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();
    Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
}

void loop()
{
    // Llegir les acceleracions i velocitats angulars
    mpu.getAcceleration(&ax, &ay, &az);
    mpu.getRotation(&gx, &gy, &gz);
    printRAW();
    delay(100);
}
```

## Llegir inclinació amb acceleròmetre

En el següent exemple, calculem la inclinació del MPU-6050 mitjançant la
projecció del mesurament de la gravetat i les relacions trigonomètriques
que podem veure en l'entrada [Cómo usar un acelerómetro con
Arduino](https://www.luisllamas.es/como-usar-un-acelerometro-arduino/).

```Arduino
/*
* Projecte nº: ARD034c
* Data: 03/02/2022
* Descripcio: Llegir inclinacio amb accelerometre
* Nota:
*
*/

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int mpuAddress = 0x68; // Pot ser 0x68 o 0x69

MPU6050 mpu(mpuAddress);

int ax, ay, az;
int gx, gy, gz;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();
    Serial.println(mpu.testConnection() ? F("IMU iniciat correctament") : F("Error al iniciar IMU"));
}

void loop()
{
    // Llegir les acceleracions
    mpu.getAcceleration(&ax, &ay, &az);

    //Calcular els angles d'inclinacio
    float accel_ang_x = atan(ax / sqrt(pow(ay, 2) + pow(az, 2)))*(180.0 / 3.14);
    float accel_ang_y = atan(ay / sqrt(pow(ax, 2) + pow(az, 2)))*(180.0 / 3.14);

    // Mostrar resultats
    Serial.print(F("Inclinacion en X: "));
    Serial.print(accel_ang_x);
    Serial.print(F("Inclinacion en Y:"));
    Serial.println(accel_ang_y);

    delay(10);
}
```

### Obtindre orientació amb giroscopi

En el següent exemple, realitzem la integració del senyal de la
velocitat del giroscopi per a obtindre l'orientació del MPU-6050, com
podem veure en l'entrada [Cómo usar un giroscopio con
Arduino](https://www.luisllamas.es/como-usar-un-giroscopio-arduino/).

```Arduino
/*
* Projecte nº: ARD034d
* Data: 03/02/2022
* Descripcio: Obtindre orientació amb giroscopi
* Nota:
*
*/

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int mpuAddress = 0x68; // Pot ser 0x68 o 0x69

MPU6050 mpu(mpuAddress);

int ax, ay, az;
int gx, gy, gz;
long tiempo_prev, dt;
float girosc_ang_x, girosc_ang_y;
float girosc_ang_x_prev, girosc_ang_y_prev;

void updateGiro()
{
    dt = millis() - tiempo_prev;
    tiempo_prev = millis();
    girosc_ang_x = (gx / 131)*dt / 1000.0 + girosc_ang_x_prev;
    girosc_ang_y = (gy / 131)*dt / 1000.0 + girosc_ang_y_prev;
    girosc_ang_x_prev = girosc_ang_x;
    girosc_ang_y_prev = girosc_ang_y;
}

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();
    Serial.println(mpu.testConnection() ? F("IMU iniciat correctament ") :F("Error al iniciar IMU"));
}

void loop()
{
    // Llegir les velocitats angulars
    mpu.getRotation(&gx, &gy, &gz);
    updateGiro();

    // Mostrar resultats
    Serial.print(F("Rotacio en X: "));
    Serial.print(girosc_ang_x);
    Serial.print(F("Rotacio en Y: "));
    Serial.println(girosc_ang_y);

    delay(10);
}
```

### Obtindre l'orientació amb filtre complementari

Aquest exemple emprem un filtre complementari per a combinar el senyal
de l'acceleròmetre i giroscopi per a obtindre un millor mesurament de
l'orientació del MPU-6050, com podem veure en l'entrada [Medir la
inclinación de un IMU con Arduino y filtro
complementario.](https://www.luisllamas.es/medir-la-inclinacion-imu-arduino-filtro-complementario/)

```Arduino
/*
* Projecte nº: ARD034e
* Data: 03/02/2022
* Descripcio: Obtindre l'orientació amb filtre complementari
* Nota:
*
*/

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int mpuAddress = 0x68; // Pot ser 0x68 o 0x69

MPU6050 mpu(mpuAddress);

int ax, ay, az;
int gx, gy, gz;
long tiempo_prev;
float dt;
float ang_x, ang_y;
float ang_x_prev, ang_y_prev;

void updateFiltered()
{
    dt = (millis() - tiempo_prev) / 1000.0;
    tiempo_prev = millis();

    //Calcular els angles amb accelerometre
    float accel_ang_x = atan(ay / sqrt(pow(ax, 2) + pow(az, 2)))*(180.0 / 3.14);
    float accel_ang_y = atan(-ax / sqrt(pow(ay, 2) + pow(az, 2)))*(180.0 / 3.14);

    //Calcular angle de rotacio amb giroscopi i filtre complementari
    ang_x = 0.98*(ang_x_prev + (gx / 131)*dt) + 0.02*accel_ang_x;
    ang_y = 0.98*(ang_y_prev + (gy / 131)*dt) + 0.02*accel_ang_y;
    ang_x_prev = ang_x;
    ang_y_prev = ang_y;
}

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();
    Serial.println(mpu.testConnection() ? F("IMU iniciat correctament") :F("Error al iniciar IMU"));
}

void loop()
{
    // Llegir les acceleracions i velocitats angulars
    mpu.getAcceleration(&ax, &ay, &az);
    mpu.getRotation(&gx, &gy, &gz);
    updateFiltered();
    Serial.print(F("Rotacio en X: "));
    Serial.print(ang_x);
    Serial.print(F(" Rotacio en Y: "));
    Serial.println(ang_y);
    delay(10);
}
```

### Obtindre l'orientació mitjançant el DMP

En aquest últim exemple emprem el DMP integrat en el MPU-6050 per a
realitzar la combinació del mesurament de l'acceleròmetre i el
giroscopi, la qual cosa proporciona millor resultats que emprar un
filtre complementari, i a més allibera a Arduino del procés de càlcul.

Perquè l'exemple funcione és necessari connectar el pin INT del MPU6050
a un pin amb interrupcions (en l'exemple, amb Arduino UNO o Nano,
connectar al Pin 2).

```Arduino
/*
* Projecte nº: ARD034g
* Data: 03/02/2022
* Descripcio: Obtindre l'orientació mitjançant el DMP
* Nota:
*
*/

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5
//INT - Pin 2

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68
// AD0 high = 0x69

MPU6050 mpu;

//MPU6050 mpu(0x69); // <-- use for AD0 high
#define INTERRUPT_PIN 2
#define LED_PIN 13

bool blinkState = false;

// MPU control/status vars
bool dmpReady = false; // set true if DMP init was successful
uint8_t mpuIntStatus; // holds actual interrupt status byte from MPU
uint8_t devStatus; // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize; // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount; // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
Quaternion q; // [w, x, y, z]
VectorInt16 aa; // [x, y, z]
VectorInt16 aaReal; // [x, y, z]
VectorInt16 aaWorld; // [x, y, z]
VectorFloat gravity; // [x, y, z]
float ypr[3]; // [yaw, pitch, roll]
volatile bool mpuInterrupt = false;

void dmpDataReady()
{
    mpuInterrupt = true;
}

void setup()
{
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
    #endif
    Serial.begin(9600);

    // Iniciar MPU6050
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // Comprobar conexion
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // Iniciar DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // Valores de calibracion
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1688);

    // Activar DMP
    if (devStatus == 0)
    {
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // Activar interrupcion
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    }
    else
    {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
}

void loop()
{
    // Si fallo al iniciar, parar programa
    if (!dmpReady) return;

    // Ejecutar mientras no hay interrupcion
    while (!mpuInterrupt && fifoCount < packetSize)
    {
    // AQUI EL RESTO DEL CODIGO DE TU PROGRRAMA
    }

    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // Obtener datos del FIFO
    fifoCount = mpu.getFIFOCount();

    // Controlar overflow
    if ((mpuIntStatus & 0x10) || fifoCount == 1024)
    {
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));
    }
    else if (mpuIntStatus & 0x02)
    {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);

        // track FIFO count here in case there is > 1 packet available (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        // MMostrar Yaw, Pitch, Roll
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        Serial.print("ypr");
        Serial.print(ypr[0] * 180/M_PI);
        Serial.print("\t");
        Serial.print(ypr[1] * 180/M_PI);
        Serial.print("\t");
        Serial.println(ypr[2] * 180/M_PI);

        // Mostrar aceleracion
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
        Serial.print("areal\t");
        Serial.print(aaReal.x);
        Serial.print("\t");
        Serial.print(aaReal.y);
        Serial.print("\t");
        Serial.println(aaReal.z);
    }
}
```

## Veure també

- [Index](../Index.md)
- [README](../README.md)
