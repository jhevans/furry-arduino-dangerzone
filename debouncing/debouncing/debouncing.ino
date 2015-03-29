// Debouncing a push button V2
// p.191 Franzis Arduino Tutorial Kit Manual

byte i = 0;
int SW1 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  digitalWrite(SW1, HIGH);
  Serial.println("Debouncing a push button V1");
}

void loop() {
  if(!digitalRead(SW1)) {
    delay(50);
    if(!digitalRead(SW1)){
      do {
      } while(!digitalRead(SW1));
      i++;
      Serial.print("Button SW1 has been pressed ");
      Serial.print(i, DEC);
      Serial.println(" times");
    }
  }
}
