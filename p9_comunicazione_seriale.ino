// Comunicazione da computer ad Arduino
const int ledPin = 13;      // dichiara il led
char tastoPremuto;          // dichiara il valore del tasto premuto
void setup() {
pinMode (ledPin, OUTPUT);
Serial.begin(9600);
}
void loop() {
if (Serial.available() > 0) {
  tastoPremuto = Serial.read();
  switch (tastoPremuto) {
    case 72:          // se viene premuto il tasto H
    digitalWrite(ledPin, HIGH);   // si accende il led
    Serial.println("Led on");     // sul monitor seriale appare il testo "Led on"
    break;
    case 76:          // se viene premuto il tasto L
    digitalWrite(ledPin, LOW);    // si spegne il led
    Serial.println("Led off");    // sul monitor seriale appare il testo "Led off"
    break;
    case 13:          // se viene premuto il tasto ritorno a capo
    break;
    case 10:          // se viene premuto il tasto nuova riga
    break;
    default:
    Serial.print("Comando sconosciuto: ");
    Serial.print(tastoPremuto);
    Serial.println(". Devi premere H o L.");
  }
}
}
