#include <Arduino.h>
#include <sensor.hpp>

Sensor::Sensor(uint8_t trig_pin, uint8_t echo_pin) 
: _trig_pin(trig_pin)
, _echo_pin(echo_pin) {
    pinMode(_trig_pin, OUTPUT);
    pinMode(_echo_pin, INPUT);
}

int Sensor::getDistanceInInches() {
    digitalWrite(_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig_pin, LOW);

    return pulseIn(_echo_pin, HIGH) / 148;
}