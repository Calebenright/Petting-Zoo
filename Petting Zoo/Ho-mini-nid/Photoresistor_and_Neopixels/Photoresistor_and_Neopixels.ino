// Code For Ho-Mini-nid
// Input: Photoresistor - Output: Neopixels

// Finds Neopixel Library
#include <Adafruit_NeoPixel.h>

// Number of Neopixels and the pin
const int npCount = 5;
const int npPin = 1;
// Declares Strip
Adafruit_NeoPixel strip (npCount, npPin);

int lightVal;
int numLed;

void setup() {
  // Clears previous strand before starting
  strip.clear();
  strip.begin();
  strip.setBrightness(250);
}

void loop() {
  
  strip.clear();
//  For Loop controls the Color and Number of Neopixels
    for (int i = 0; i < numLed; i++) {
      strip.setPixelColor(i, strip.Color(0, 0, 255));
    }
  strip.show();

  // Reads the amount of light input (from 0 to 1023)
  lightVal = analogRead(A1);

  // Photoresistor Value Thresholds
  if (lightVal < 750) {
    // Room
    numLed = 0;
  } else if (lightVal < 800) {
    // Room+
    numLed = 1;
  } else if (lightVal < 900) {
    // Room++
    numLed = 2;
  } else if (lightVal < 950) {
    // Room + light towards sensor
    numLed = 3;
  } else if (lightVal > 1000) {
    // Light on Sensor
    numLed = 0;
  } else {
    // Brightest
    numLed = 4;
  }
}
