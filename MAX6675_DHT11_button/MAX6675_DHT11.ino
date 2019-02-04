// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11   // DHT 11
int last_state;
int button_pin = 2;

int ledPin=12;
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
int minuti = 1;
int thermtemp = 0;

//unsigned long old_millis = 0;
//unsigned long delta = 1000;
float temp;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode (8, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (button_pin, INPUT);
  Serial.begin(9600);
  
 

  Serial.println("Millis_DHT11_MAX6675");
delay (500);

}

void loop() {
  delay (1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  //unsigned long now = millis();
  
  int button_state = digitalRead (button_pin);
  
  if (button_state == HIGH && button_state != last_state) {
    digitalWrite (ledPin, HIGH);
    float dhttemp = dht.readTemperature();
    int thermtemp = thermocouple.readCelsius();
    Serial.print (millis());
    Serial.print (", ");
    Serial.print (dhttemp);
    Serial.print (", ");
    Serial.println (thermtemp);
    //old_millis = now;
    //minuti = minuti + 1;
    temp = thermocouple.readCelsius ();
    digitalWrite (ledPin, LOW);
  }
  //il led si attiva quando la temperatura supera i 27 gradi
  if (temp > 27) {
    digitalWrite (8, HIGH);
  }
  //il led si spegne quando la temperatura va sotto i 27 gradi
  if (temp < 27) {
    digitalWrite (8, LOW);
  }
  last_state = button_state;
  delay(1);
}
