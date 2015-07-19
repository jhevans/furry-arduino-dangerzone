// Circuit tester
int OUT_0 = 10; // High
int OUT_1 = 11; // Alternating high low
int OUT_2 = 12; 
int OUT_3 = 13;

int DELAY_LENGTH = 250;

void setup() {
  pinMode(OUT_0, OUTPUT);
  pinMode(OUT_1, OUTPUT);

  digitalWrite(OUT_0, HIGH);
}

void loop() {
  digitalWrite(OUT_1, HIGH);
  delay(DELAY_LENGTH);
  digitalWrite(OUT_1, LOW);
  delay(DELAY_LENGTH);
}
