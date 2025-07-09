#include <stdint.h>

#ifndef __SENSOR_H__
#define __SENSOR_H__

class Sensor {

public:
    Sensor(uint8_t trig_pin, uint8_t echo_pin);
    int getDistanceInInches();

private:
    uint8_t _trig_pin;
    uint8_t _echo_pin;

};

#endif /* __SENSOR_H */