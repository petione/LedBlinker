
LedBlinker
===============
#include <Arduino.h>

#include <LedBlinker.h>

LedBlinker Led(LED_BUILTIN);

void setup() {

Serial.begin(9600);

// Led.setDelay(50,500,3,6000);// migniecia trwajace 50ms, co 500ms 3 razy i 6s przerwy

  Led.setDelay(50, 500, 6); // migniecia trwajace 50ms, co 500ms 3 razy
  
  //Led.setDelay(50, 500); //ciągłe migniecia trwajace 50ms, co 500ms
  
  //Led.setDelay(500);// miganie co 500ms
  
  Led.start();
  
  // put your setup code here, to run once:
  
}


void loop() {

 Led.blink();
 
}
