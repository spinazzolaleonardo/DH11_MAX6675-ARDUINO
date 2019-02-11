const int elements_number = 10;
int avg_store[elements_number];
int counter = 0;
int AnPin = A0;

void setup () {
  Serial.begin(9600);
}
void loop () {
  avg_store [counter % elements_number] = analogRead (AnPin); //inserisco in avg store il resto della divisione% (modulo, ottengo nuemri che vanno da 0 a 9);
  counter ++;  //somma fino ad arrivare a 10; si fa il FIFO (First In First Out); ciclo tra 0 e 9 nell'array;
  long value = 0;  
for (int i = 0; i < elements_number; i++) //si fa la sommatoria;
{
  value += avg_store [i];    //ad ogni ciclo si immagazzinano 10 valori e si fa la media, poi delay di 1000;

}
value = value / elements_number; //si divide per il numero degli elementi;
Serial.print (" it :");
Serial.print (counter);
Serial.print (", avg: ");
Serial.print (value);
delay (1000);
}
