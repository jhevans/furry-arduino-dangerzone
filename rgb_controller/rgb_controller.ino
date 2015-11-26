int R = 10; 
int G = 11; 
int B = 12; 

int DELAY_LENGTH = 750;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  red(HIGH);
  green(LOW);
  blue(LOW);
  delay(DELAY_LENGTH);
  red(LOW);
  green(HIGH);
  blue(LOW);
  delay(DELAY_LENGTH);
//  red(HIGH);
//  green(HIGH);
//  blue(LOW);
//  delay(DELAY_LENGTH);
//  red(LOW);
//  green(HIGH);
//  blue(HIGH);
//  delay(DELAY_LENGTH);
//  red(HIGH);
//  green(LOW);
//  blue(HIGH);
//  delay(DELAY_LENGTH);
  red(LOW);
  green(LOW);
  blue(HIGH);
  delay(DELAY_LENGTH);
  red(HIGH);
  green(HIGH);
  blue(HIGH);
  delay(DELAY_LENGTH);
  while(true){
  }
}

void red(int on){
  digitalWrite(R,on);
}
void green(int on){
  digitalWrite(G, on);
}
void blue(int on){
  digitalWrite(B,on);
}

