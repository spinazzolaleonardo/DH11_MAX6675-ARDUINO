#include <IRremote.h>
int rxPin = 13;             //dichiaro il pin su cui connetto il sensore
IRrecv irrecv (rxPin);     //dichiaro l'oggetto ricevitore
decode_results results;   //dichiaro oggetto per tradurre

void setup() {
Serial.begin (9600);
irrecv.enableIRIn();      //abilito la lettura; si occupa di immagazzinare il messaggio, è sempre in ascolto
 
}

void loop() 
 { if (irrecv.decode (&results)) {             //se il sensore percepisce; (.decode)traduce quei messaggi in esadecimale; & serve per passare l'indirizzo della cella di memoria dove andrà a registrare il valore
    Serial.println (results.value, HEX);       //allora scrive il valore in esadecimale
    irrecv.resume ();                          //resetto la comunicazione
  }
  

}
