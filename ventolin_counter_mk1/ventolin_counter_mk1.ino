// This program is a simple counter incremented by a single button.  There are 3 LED's to indicate how many times the 
// button has been pressed since the system was last reset. 

// From 0-GREEN_LIMIT presses the green light will be lit
// from GREEN_LIMIT-AMBER_LIMIT the amber light will be lit
// above AMBER_LIMIT the red light will be lit

// An LED is lit whenever the button is pressed and turns off after LIGHT_DELAY milliseconds

// Runs on Arduino UNO and Adafruit trinket

int i,x;
int RED_LED = 11;
int AMBER_LED = 12;
int GREEN_LED = 13;
int BTN = 10;
int DELAY = 20;

int GREEN_LIMIT = 150;
int AMBER_LIMIT = 175;
//int GREEN_LIMIT = 5;
//int AMBER_LIMIT = 7;

int count = 0;
int btnValue1, btnValue2 = 0;

void setup(){
//  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  pinMode(BTN, INPUT);
  digitalWrite(BTN, HIGH);
}

void loop(){
  while(true){
//    printBtn();
//    Serial.print("count: ");
//    Serial.println(count);
    detectButtonPress();
    if(count < GREEN_LIMIT) blinkOnce(GREEN_LED, DELAY);
    else if (count < AMBER_LIMIT) blinkOnce(AMBER_LED, DELAY);
    else blinkOnce(RED_LED, DELAY);
  }
}

void printBtn(){
  Serial.println(digitalRead(BTN));
}

void detectButtonPress(){
  btnValue1 = digitalRead(BTN);
//  Serial.print("btnValue1: ");
//  Serial.println(btnValue1);
  if(btnValue1 == LOW){
    delay(50);
    btnValue2 = digitalRead(BTN);
//    Serial.print("btnValue1: ");
//    Serial.println(btnValue2);
    if(btnValue2 == LOW){
      count++;
      while(!digitalRead(BTN)){
        // Do nothing
      }
    }
  }
}

void blinkOnce(int pin, int DELAY){
    digitalWrite(pin, HIGH);
    delay(DELAY);
    digitalWrite(pin, LOW);
}

