// Debouncing a push button V4
// p.191 Franzis Arduino Tutorial Kit Manual

int i = 0;
int SW1 = 12;
int LED = 13;
byte flag = 0;
byte value_1, value_2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  digitalWrite(SW1, HIGH);
  pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
  Serial.println("Switch on delay");
}

void loop() {
  value_1 = digitalRead(SW1);
  if (!value_1){
    delay(50);
    value_2 = digitalRead(SW1);
    if (!value_2){
      flag=1;
      do{
      }while(!digitalRead(SW1));
    }
  }
  if (flag==1)i++;
  if(i>3000){
    digitalWrite(LED, LOW);
    while(1);
  }
  delay(1);
}
