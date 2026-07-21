#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <Arduino.h>

class Calibration
{
public:
    Calibration();

    void begin();

    void start();

    void update();

    bool isFinished();

    uint16_t getMin(uint8_t sensor);
    uint16_t getMax(uint8_t sensor);

    uint16_t normalize(uint8_t sensor, uint16_t value);

private:
    bool finished;

    uint16_t minValue[6];
    uint16_t maxValue[6];
};

#endif