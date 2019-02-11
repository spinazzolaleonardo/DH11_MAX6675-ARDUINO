#include <Servo.h>
int potpin = 0;
int pushbutton = 7;
int val;
int digitalval = 0;
int counter = 0;
Servo Servo1;
Servo Servo2;


void setup () {
  Servo2.attach (4);
  Servo1.attach (2);
  pinMode (pushbutton, INPUT);
}
void loop () {

int state = digitalRead (pushbutton);
  if (state == HIGH) {
    counter ++;
    delay (150);
Servo1.write (150);
delay (50);
Servo2.write (150);
delay (500);

val = analogRead (potpin);
val = map (val, 0, 1023, 0, 150);
Servo1.write (val);
delay (15);

val = analogRead (potpin);
val= map (val, 0, 1023, 150, 0);
Servo2.write (val);
delay (15);
  
}
}

