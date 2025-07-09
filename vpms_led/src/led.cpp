#include <Arduino.h>
#include <led.hpp>

LED::LED(uint8_t pin, uint8_t bps) 
: _pin(pin)
, _bps(bps)
, _blinking(false)
, _ledState(false) {
    pinMode(_pin, OUTPUT);
}

void LED::on() {
    if (!_blinking) {
        _blinking = true;
        _ledState = true;
        _lastToggleTime = millis();
        digitalWrite(_pin, HIGH);
    }
}

void LED::off() {
    if (_blinking || _ledState) {
        _blinking = false;
        _ledState = false;
        digitalWrite(_pin, LOW);
    }
}

void LED::update() {
    if (!_blinking) return;

    unsigned long now = millis();
    unsigned long interval = 500 / _bps;  // half-cycle for on/off

    if (now - _lastToggleTime >= interval) {
        _lastToggleTime = now;
        _ledState = !_ledState;
        digitalWrite(_pin, _ledState ? HIGH : LOW);
    }
}