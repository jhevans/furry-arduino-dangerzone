// LED Dimmer

int brightness = 0;
int SW1 = 3;
int SW2 = 2;
int LED = 11;
float pi = 3.14;

void setup(){
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  digitalWrite(SW1, HIGH);
  pinMode(SW2, INPUT);
  digitalWrite(SW2, HIGH);
}

void loop(){
  
  for(int i=0; i<256; i++){
    float val = float(i)/256.0;
    Serial.println(val);
    float sinVal = sin(val*2.0*pi) + 1.0;
    Serial.println(sinVal);
    brightness = sinVal*128.0;
    Serial.println(brightness);
    analogWrite(LED, brightness);
    delay(500);
  }  
}
