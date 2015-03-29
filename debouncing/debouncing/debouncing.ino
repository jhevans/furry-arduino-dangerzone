// Debouncing a push button V4
// p.191 Franzis Arduino Tutorial Kit Manual

byte i = 0;
int SW1 = 12;
int LED = 13;
int TOG = 0;
byte value_1, value_2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  digitalWrite(SW1, HIGH);
  pinMode(LED, OUTPUT);
  Serial.println("Debouncing a push button V4");
}

void loop() {
  value_1 = digitalRead(SW1);
  if (!value_1){
    delay(50);
    value_2 = digitalRead(SW1);
    if (!value_2){
      i++;
      Serial.print("Button SW1 was pressed ");
      Serial.print(i, DEC);
      Serial.println(" times");
      if (TOG!=0) TOG=0; else TOG=1;
      digitalWrite(LED, TOG);
      do{
      }while(!digitalRead(SW1));
    }
  }
}
