#ifndef IRSENSOR_H
#define IRSENSOR_H

#include <Arduino.h>
#include "Config.h"

class IRSensor
{
public:
    void begin();

    uint16_t readLeftFront();
    uint16_t readLeftDiagonal();
    uint16_t readFrontLeft();
    uint16_t readFrontRight();
    uint16_t readRightDiagonal();
    uint16_t readRightFront();

    void readAll();

    uint16_t getLeftFront();
    uint16_t getLeftDiagonal();
    uint16_t getFrontLeft();
    uint16_t getFrontRight();
    uint16_t getRightDiagonal();
    uint16_t getRightFront();

private:
    uint16_t leftFront;
    uint16_t leftDiagonal;
    uint16_t frontLeft;
    uint16_t frontRight;
    uint16_t rightDiagonal;
    uint16_t rightFront;

    uint16_t readSensor(uint8_t ledPin, uint8_t adcPin);
};

#endif