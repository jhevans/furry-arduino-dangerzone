//ADC
// With a potentiometer/trimmer attached to ADC0 will adjust the duration of blinks according to measured resistance

int ADC0 = 0;
int value;
int ledPin = 13;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  value = analogRead(ADC0);
  Serial.print("ADC0 = ");
  Serial.println(value);
  
  blinkOnce(ledPin, value);
}


void blinkOnce(int pin, int delayLength){
  Serial.println(pin);
  Serial.println(delayLength);
  digitalWrite(pin, HIGH);
  delay(delayLength);
  digitalWrite(pin, LOW);
  delay(delayLength);
}
