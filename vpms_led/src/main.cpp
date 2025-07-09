#include <Arduino.h>
#include <led.hpp>
#include <sensor.hpp>

// Distances (inches)
#define RED 6
#define YELLOW 12
// #define GREEN 24

// HC-SR04 sensor pins
#define PIN_TRIG 3
#define PIN_ECHO 2

// LED pins
const int PIN_LED_RED = A3;
const int PIN_LED_YELLOW = A4;
const int PIN_LED_GREEN = A5;

// LEDs
LED redLED(PIN_LED_RED, 5);       // 5 blinks/sec
LED yellowLED(PIN_LED_YELLOW, 3); // 3 blinks/sec
LED greenLED(PIN_LED_GREEN, 1);   // 1 blink/sec

// HC-SR04 sensor
Sensor HCSR04(PIN_TRIG, PIN_ECHO); 


void setup() {
  Serial.begin(115200);
}

void loop() {
    int distance = HCSR04.getDistanceInInches();

    Serial.print("Distance in inches: ");
    Serial.println(distance);

    if (distance <= RED) {
        redLED.on();
        yellowLED.off();
        greenLED.off();
    } else if (distance <= YELLOW) {
        redLED.off();
        yellowLED.on();
        greenLED.off();
    } else { // Green
        redLED.off();
        yellowLED.off();
        greenLED.on();
    }

      redLED.update();
      yellowLED.update();
      greenLED.update();

    delay(100);
}