// Serial IO test

char input;
char output;

void setup(){
  Serial.begin(9600);
  Serial.println("Serial.available() function");
  Serial.println();
}

void loop(){
  if(Serial.available() > 0){
    input = Serial.read();
    Serial.print("I received the following character: ");
//    output = char(input);
    output = input;
    Serial.print(output);
    Serial.print(" (DEC: ");
    Serial.print(byte(output));
    Serial.print(", HEX: ");
    Serial.print(byte(output), HEX);
    Serial.print(")");
    Serial.println();
  }
}
