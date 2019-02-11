#include <Servo.h>
int potpin = 0;

int val;
Servo Servo1;
Servo Servo2;


void setup () {
  Servo2.attach (4);
  Servo1.attach (2);
}
void loop () {

val = analogRead (potpin);
val = map (val, 0, 1023, 0, 150);
Servo1.write (val);
delay (15);

val = analogRead (potpin);
val= map (val, 0, 1023, 150, 0);
Servo2.write (val);
delay (15);
  

}

