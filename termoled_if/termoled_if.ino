// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
int minuti=1;
unsigned long old_millis=0;
unsigned long delta=2000;
float temp;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;
  
void setup() {
  pinMode (8, OUTPUT);
  pinMode (12, OUTPUT);
  Serial.begin(9600);
 
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  
  Serial.println("MAX6675 test");
 
  delay(500);
}

void loop() {
  unsigned long now=millis();
  digitalWrite (12, HIGH);
  delay (1000);
  digitalWrite (12, LOW);
  if(now>=old_millis+delta) {
    
    delay (2000);
    Serial.print (minuti);
    Serial.print (", ");
    Serial.println (thermocouple.readCelsius ());
    old_millis=now;
    minuti=minuti+1;
    temp=thermocouple.readCelsius ();
  }
if (temp>27) {
digitalWrite (8, HIGH);
}
if (temp<27) {
  digitalWrite (8, LOW);
}
   delay(1);
}
