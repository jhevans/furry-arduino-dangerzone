// Blink
// Uses LED L on the Arduino board
#define arrayLength 6

int ledPin = 13;  // LED is connected with digital pin 13
int numbers[] = {1,4,6,7,8,24};

// the setup routine configures the digital port
// This routine is only executed once at program start!

void setup(){
  Serial.begin(9600);
  // The pin is configured as output
  pinMode(ledPin, OUTPUT);
  Serial.println("What say you men?");
  Serial.println();
}

// The main program is an infinite loop
void loop(){
  int sum = 0;
  for(int i=0; i<arrayLength; i++){
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

  int count = 0;
  while(true){
    
    if(count == 100){
      Serial.println("You should probably turn me off now");
    }
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
    count++;
    continue;
  }
}

