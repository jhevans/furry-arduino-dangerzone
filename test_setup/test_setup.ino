// Circuit tester
int OUT_0 = 10; // High
int OUT_1 = 11; // Alternating high low
int OUT_2 = 12; // Alternating low high
int OUT_3 = 13;

int DELAY_LENGTH = 250;

void setup() {
  pinMode(OUT_0, OUTPUT);
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);

  digitalWrite(OUT_0, HIGH);
}

void loop() {
  digitalWrite(OUT_1, HIGH);
  digitalWrite(OUT_2, LOW);
  delay(DELAY_LENGTH);
  digitalWrite(OUT_1, LOW);
  digitalWrite(OUT_2, HIGH);
  delay(DELAY_LENGTH);
}
