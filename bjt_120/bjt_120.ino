int potPin = A0;
int motPin = A1;

void setup () {
  Serial.begin (9600);
  pinMode (motPin, OUTPUT);
  Serial.print ("pot value");
  Serial.print (" , ");
  Serial.println (" mot value");
}
void loop () {
  int potValue = analogRead (potPin);
  int motValue = map (potValue, 0, 1023, 0, 255);
  analogWrite (motPin, motValue);
  Serial.print (potValue);
  Serial.print (" , ");
  Serial.println (motValue);
}
  


