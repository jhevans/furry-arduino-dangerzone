// Software UART

#include<SoftwareSerial.h>

#define rxPin 2
#define txPin 3
#define ledPin 13

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);
byte pinState = 0;

void setup(){
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  mySerial.begin(9600);
}

void loop(){
  char someChar = mySerial.read();
  mySerial.print(someChar);
  
  toggle(13);
}

void toggle(int pin){
  digitalWrite(pin, pinState);
  pinState = !pinState;
}
