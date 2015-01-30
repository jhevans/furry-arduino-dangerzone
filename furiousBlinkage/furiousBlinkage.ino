// Blink
// Uses LED L on the Arduino board

int ledPin = 13;  // LED is connected with digital pin 13

// the setup routine configures the digital port
// This routine is only executed once at program start!

void setup(){
  // The pin is configured as output
  pinMode(ledPin, OUTPUT);
}

// The main program is an infinite loop
void loop(){
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(ledPin, LOW);
  delay(50);
}

