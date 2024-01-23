/*
 * CARTROTECH  (www.cartrotech.wordpress.com)
 * 
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
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);
}
