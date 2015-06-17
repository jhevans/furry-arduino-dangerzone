// Blink
// Uses LED L on the Arduino board
#define arrayLength 6

int i,x;
int RED_LED = 11;  
int AMBER_LED = 12;
int GREEN_LED = 13;
int BTN1 = 10;

int GREEN_LIMIT = 150;
int AMBER_LIMIT = 175;

void setup(){
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  pinMode(BTN1, INPUT);
}

void loop(){
  int count = 0;
  int delayLength = 20;
  while(true){
    count++;
    if(count < GREEN_LIMIT) blinkOnce(GREEN_LED, delayLength);
    else if (count < AMBER_LIMIT) blinkOnce(AMBER_LED, delayLength);
    else blinkOnce(RED_LED, delayLength);
  }
}

void blinkOnce(int pin, int delayLength){
    digitalWrite(pin, HIGH);
    delay(delayLength);
    digitalWrite(pin, LOW);
}

