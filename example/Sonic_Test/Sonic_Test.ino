#include <Sonic.h>

//Declare Sonic object. Then for the parameters choose two IO pins
//for your Ultrasonic range finder's 'Trig' and 'Echo' pins.
//Timeout is set to 22000UL by default. That is the amount of time it takes
//sound to travel 375cm and bounce off an object and travel 375cm back to the 
//ultrasound receiver.
//If you wish to change that based on your modules accuracy just add the
//amount of microseconds in the parameters of the Sonic object declaration.
//Sonic sonic(<Trigger pin>, <Echo pin>, <Timeout>);
Sonic sonic(7,8);

void setup() {
  Serial.begin(9600);
  
  sonic.setTimeout(22000UL);
}

void loop() {
  Serial.print("Distance in CM: ");
  Serial.println(sonic.read());
  delay(1000);
}
