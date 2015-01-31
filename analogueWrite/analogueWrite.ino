// Analogue write
// Fadey lights, if you connect some LED's to 10 and 11 along with all the requisite resistors to keep them from blowing up then they will fade on and off alternately

int value;
int ledGreen = 10;
int ledRed = 11;

void setup(){
  
}

void loop(){
  for(value=0; value<255; value++){
    analogWrite(ledGreen, value);
    analogWrite(ledRed, 255 -value);
    delay(5);
  }
  
  delay(1000);
  for(value=255; value!=0; value--){
    analogWrite(ledGreen, value);
    analogWrite(ledRed, 255 -value);
    delay(5);
  }
  delay(1000);
  
}
