// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11   // DHT 11
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
int minuti = 1;
int thermtemp = 0;
unsigned long old_millis = 0;
unsigned long delta = 2000;
float temp;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode (8, OUTPUT);
  pinMode (12, OUTPUT);
  Serial.begin(9600);
  Serial.println(F("DHT_MAX6675"));
 

  Serial.println("MAX6675&DHT11 test");

  delay(500);
}

void loop() {
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  unsigned long now = millis();
  digitalWrite (12, HIGH);
  delay (1000);
  digitalWrite (12, LOW);
  if (millis() - old_millis >= delta) {
    float dhttemp = dht.readTemperature();
    int thermtemp = thermocouple.readCelsius();
    Serial.print (minuti);
    Serial.print (", ");
    Serial.print (dhttemp);
    Serial.print (", ");
    Serial.println (thermtemp);
    old_millis = now;
    minuti = minuti + 1;
    temp = thermocouple.readCelsius ();
  }
  //il led si attiva quando la temperatura supera i 27 gradi
  if (temp > 27) {
    digitalWrite (8, HIGH);
  }
  //il led si spegne quando la temperatura va sotto i 27 gradi
  if (temp < 27) {
    digitalWrite (8, LOW);
  }
  delay(1);
}
