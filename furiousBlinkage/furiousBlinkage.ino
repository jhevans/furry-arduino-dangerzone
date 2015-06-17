// Blink
// Uses LED L on the Arduino board
#define arrayLength 6

int i,x;
int ledPin = 12;  // LED is connected with digital pin 13
int numbers[] = {1,4,6,7,8,24};

// the setup routine configures the digital port
// This routine is only executed once at program start!

void setup(){
  Serial.begin(9600);
  // The pin is configured as output
  pinMode(ledPin, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  Serial.println("What say you men?");
  Serial.println();
}

// The main program is an infinite loop
void loop(){
  int sum = 0;
  for(i=0; i<arrayLength; i++){
    Serial.print(numbers[i]);
    if(i != arrayLength -1){
      Serial.print("+");
    }
    sum += numbers[i];
  }
  Serial.print(" yields ");
  Serial.print(sum);
  Serial.println(" sir!");
  Serial.println();
  
  int result;
  for(x=0; x<=20; x++){
    result = map(x, 0, 20, 5, 15);
    Serial.println(result);
  }

  int count = 0;
  int delayLength = 250;
  while(true){    
    if(count == 10){
      Serial.println("You should probably turn me off now");
      delayLength = 1000;
    }
    blinkOnce(ledPin, delayLength);
    count++;
  }
}

void blinkOnce(int pin, int delayLength){
    digitalWrite(pin, HIGH);
    digitalWrite(13, HIGH);
    delay(delayLength);
    digitalWrite(pin, LOW);
    digitalWrite(13, LOW);
    delay(delayLength);
}

