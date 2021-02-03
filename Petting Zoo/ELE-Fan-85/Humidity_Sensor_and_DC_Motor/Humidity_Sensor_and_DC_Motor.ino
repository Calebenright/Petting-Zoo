// Code For Ele-Fan-85
// Input: Humidity Sensor - Output: DC Motor

// Source: circuitbasics.com
// These Lines Connect to the Humidity Sensor
#include <dht.h>
dht DHT;
#define DHTPIN 2

int motorPin = 1;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {

  int chk = DHT.read11(DHTPIN);
  // Checks to see if the sensor is damp
    if (DHT.humidity > 50) {
      // If yes, spin motor
      digitalWrite(motorPin, HIGH);
      } 
// CODE THAT DID NOT WORK
//    else if (DHT.humidity < 20) {
//      digitalWrite(motorPin, LOW);
//    }

    // arbitrary delay to give time to "dry off"
    delay(5000);
    digitalWrite(motorPin, LOW);
  }
