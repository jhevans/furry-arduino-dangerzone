// Blink
// Uses LED L on the Arduino board
#define arrayLength 6

int i,x;
int LED1 = 11;  
int LED2 = 12;
int LED3 = 13;
int BTN1 = 10;

void setup(){
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  pinMode(BTN1, INPUT);
}

void loop(){
  int count = 0;
  int delayLength = 500;
  int value = 0;
  while(true){
    if(count % 10 == 0){
      value =  digitalRead(BTN1);
    }
    Serial.println(value);
    if(value == 1){
      blinkOnce(LED1, delayLength);
      blinkOnce(LED2, delayLength);
      blinkOnce(LED3, delayLength);
      blinkOnce(LED2, delayLength);
    }
  }
}

void blinkOnce(int pin, int delayLength){
    digitalWrite(pin, HIGH);
    delay(delayLength);
    digitalWrite(pin, LOW);
    delay(delayLength);
}

