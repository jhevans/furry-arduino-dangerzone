// Morse encoder

char encoding[][7] = {
  // A
  ".-    ", 
  //B	
  "-...  ",
  //C	
  "-.-.  ",
  //D	
  "-..   ",
  //E	
  ".     ",
  //F	
  "..-.  ",
  //G	
  "--.   ",
  //H	
  "....  ",
  //I	
  "..    ",
  //J	
  ".---  ",
  //K	
  "-.-   ",
  //L	
  ".-..  ",
  //M	
  "--    ",
  //N	
  "-.    ",
  //O	
  "---   ",
  //P	
  ".--.  ",
  //Q	
  "--.-  ",
  //R	
  ".-.   ",
  //S	
  "...   ",
  //T	
  "-     ",
  //U	
  "..-   ",
  //V	
  "...-  ",
  //W	
  ".--   ",
  //X	
  "-..-  ",
  //Y	
  "-.--  ",
  //Z	
  "--..  ",
};

int ledPin = 13;
int buzzerPin = 11;
int timeUnit = 50;
int dotLength = timeUnit;
int dashLength = 3*timeUnit;
int interElementGapLength = timeUnit;
int letterGapLength = 2*timeUnit;  
int spaceLength = 4*timeUnit;
int ucOffset = 65;  // Upper case ASCII character offset
int lcOffset = 97;  // Lower case ASCII character offset

char input;
byte correctedInput;


void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Send me strings and I shall Morsinate them!");
}

void loop(){
  byte inputByte;
//  char morseString[7];
  if(Serial.available() > 0){
    input = Serial.read();
//    Serial.print("input char: ");
//    Serial.println(input);
    if(input == 32){  // space
      space();
      return;
    } else if(input == 10){  // newline
      Serial.println();
      return;
    }
    inputByte = charToNormalisedByte(input);
//    Serial.print("encoded output: ");
//    Serial.print(encoding[inputByte]);
    // TODO: refactor this into a function
    for(int i=0; i<7; i++){
      switch(encoding[inputByte][i]){
        case '.':
          dot();
          delay(interElementGapLength);
          break;
        case '-':
          dash();
          delay(interElementGapLength);
          break;
        default:
          continue;      
      }
    }
    delay(letterGapLength);
    Serial.print(' ');
  }
}

byte charToNormalisedByte(char sourceChar){
  byte inputByte;
  inputByte = int(sourceChar);
  if(inputByte >= lcOffset){
    correctedInput = inputByte - lcOffset;
  } else if( inputByte >= ucOffset){
    correctedInput = inputByte - ucOffset;
  }
    
//    Serial.print("corrected input byte: ");
//    Serial.println(correctedInput);
  return correctedInput;  
}

void dot(){
  blinkOnce(dotLength);
  Serial.print('.');
}

void dash(){
  blinkOnce(dashLength);
  Serial.print('-');
}

void space(){
  delay(spaceLength);
  Serial.print("   ");
}

void blinkOnce(int delayLength){
    digitalWrite(ledPin, HIGH);
    analogWrite(buzzerPin, 127);
    delay(delayLength);
    digitalWrite(ledPin, LOW);
    analogWrite(buzzerPin, 0);
}
