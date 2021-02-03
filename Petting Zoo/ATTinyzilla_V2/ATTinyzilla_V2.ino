// Code For ATTinyzilla
// Input: Touch Sensor - Output: LED's

// Library for Touch Sensing
#include <CapacitiveSensor.h>

int ledPin =  1;
unsigned long endTime = 0;
unsigned long startTime;
// Controls speed of blinking LED
long interval = 100;        

int ledBlink = LOW;
int switchVal = 0;
// Debounce For Touch Sensor
int prevTouch;
// Numbers indicate the pins used for touch sensing
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  long touch =  cs_4_2.capacitiveSensor(30);
  
  // Case Switching Debounce
  if (touch > 40 && prevTouch < 40) {
    if (switchVal == 2) {
      switchVal = 0;
    } else {
      switchVal = switchVal + 1;
    }
  }

  switch (switchVal) {
    case 0:
     // starts millis timer
      startTime = millis();        

      if (startTime - endTime >= interval) {
        // resets timer
        endTime = startTime;        
        // Blinking LED Function
        if (ledBlink == LOW) {
          ledBlink = HIGH;
        } else {
          ledBlink = LOW;
        }
        digitalWrite(ledPin, ledBlink);
      }
      break;
    case 1:
      digitalWrite(ledPin, LOW);
      break;
    case 2:
      digitalWrite(ledPin, HIGH);
      break;
  }
  prevTouch = touch;
}
