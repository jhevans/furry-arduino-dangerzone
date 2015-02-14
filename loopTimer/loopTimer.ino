// simple loop timer utility

unsigned long setupStart, setupEnd, setupDuration, loopStart, loopEnd, loopDuration;
unsigned long cumulativeTime = 0;
unsigned long avgTime;

int iteration = 0;
int nIterations = 100;
int done = false;


void setup(){
  Serial.begin(9600);
  Serial.println("Loop timer");
  
  setupStart = micros();
  // Put code to be timed here
  
  // end timed code
  setupEnd = micros();
  setupDuration = setupEnd-setupStart;
  Serial.print("setup time: ");
  Serial.print(setupDuration);
  Serial.println("us");
};

void loop(){
  
  if(iteration < nIterations){
      Serial.print("loop time: ");
      
      loopStart = micros();
      // Put code to be timed here
      
      // end timed code
      loopEnd = micros();
      loopDuration = loopEnd-loopStart;
      Serial.print("loop time: ");
      Serial.print(loopDuration);
      Serial.println("us");
      
      iteration++;
      cumulativeTime += loopDuration;
  }
  else if(!done){
      Serial.print("Cumulative time for ");
      Serial.print(iteration);
      Serial.print(" iterations: ");
      Serial.print(cumulativeTime);
      Serial.println();
      
      Serial.print("Average time over ");
      Serial.print(iteration);
      Serial.print(" iterations: ");
      Serial.print(cumulativeTime/iteration);
      Serial.println();
      
      done = true;
  }
}
