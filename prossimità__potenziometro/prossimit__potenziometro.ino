#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11 

#include <HCSR04.h>
UltraSonicDistanceSensor distanceSensor (8, 7);

DHT dht(DHTPIN, DHTTYPE);
int last_state =0;
unsigned long last_now = 0;
int delta = 1000;
int ledRPin1 = 3;
int ledRPin2 = 4;
int ledGPin = 5;
int button = 2;
int potPin= A0;
int analogval=0;
int soglia;
void setup() {
 
pinMode (2, INPUT);
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
Serial.begin (9600);
Serial.println ("time, prossimity, temperature, relative humidity");
}
void loop()
{  int m = distanceSensor.measureDistanceCm ();
 soglia= analogRead (potPin);
  if (m>soglia) { 
  digitalWrite (ledGPin, LOW);
    int val;
    soglia= analogRead (potPin);
    soglia= map (val, 0, 1023, 4, 400);  //mappo il valore letto

}
  unsigned long now = millis();     //codice per produrre eventi a tempo: ogni secondo fa una misura
  if (now - last_now >= delta) {
    last_now = now;
    digitalWrite (ledGPin, HIGH);
    float t = dht.readTemperature ();
    float h = dht.readHumidity ();
    int m = distanceSensor.measureDistanceCm ();

    int sommatoria = 0;
    int number = 25;
    for (int i = 0; i < number; i++) {
      int d = distanceSensor.measureDistanceCm ();
      if (d != -1) sommatoria += distanceSensor.measureDistanceCm();
      else i--;
      delay (5);
    }
  }

    digitalWrite (ledGPin, LOW);
    Serial.print (now);
    Serial.print (", ");
    Serial.print (distanceSensor.measureDistanceCm());
    Serial.print (", ");
    Serial.print (dht.readTemperature());
    Serial.print (", ");
    Serial.println (dht.readHumidity());

    if  (dht.readTemperature() > 30) {
    digitalWrite (ledRPin1, HIGH); }
    if (dht.readHumidity() < 50) {
    digitalWrite (ledRPin2, HIGH);  }
      

  int state = digitalRead (button);
  if (state ==1 && last_state != state) { 
    digitalWrite (ledRPin1, LOW);
    digitalWrite (ledRPin2, LOW);
  }
  }
 
 
  



