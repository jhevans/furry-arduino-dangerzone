// Debouncing a push button V1
// p.191 Franzis Arduino Turoial Kit Manual

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
      Serial.println("Button SW1 has been pressed");
    }
  }
}
