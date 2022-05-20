#include <Arduino.h>

// the number of the LED pin
const int ledPin1 = 5;  // 5 corresponds to GPIO5
const int ledPin2 = 15;
const int ledPin3 = 2;

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8; // 8 bit -- 2^8 = 256 --> control the LED brightness value from 0-255
 
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin1, ledChannel);
  ledcAttachPin(ledPin2, ledChannel);
  ledcAttachPin(ledPin3, ledChannel);
}
 
void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}