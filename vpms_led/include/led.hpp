#include <stdint.h>

#ifndef __LED_H__
#define __LED_H__

class LED {
  public:
    LED(uint8_t pin, uint8_t bps);
    void on(); // start blinking
    void off(); // stop blinking
    void update(); // must be called frequently in main loop

  private:
    uint8_t _pin;
    uint8_t _bps; // blinks per second
    bool _blinking; // whether blinking is active
    bool _ledState; // current physical state (HIGH or LOW)
    unsigned long _lastToggleTime;  // last toggle timestamp
};

#endif /* __LED_H */