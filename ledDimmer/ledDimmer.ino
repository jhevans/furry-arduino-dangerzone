// LED Dimmer

int brightness = 255;
int SW1 = 3;
int SW2 = 2;
int LED = 11;

void setup(){
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  digitalWrite(SW1, HIGH);
  pinMode(SW2, INPUT);
  digitalWrite(SW2, HIGH);
}

void loop(){
  if(!digitalRead(SW1)&&digitalRead(SW2)){
    Serial.println("SW2");
    if(brightness<255)brightness++;
  }
  else if(digitalRead(SW1)&&!digitalRead(SW2)){
    Serial.println("SW1");
    if(brightness>0)brightness--;
  }
  analogWrite(LED, brightness);
  delay(10);
}
