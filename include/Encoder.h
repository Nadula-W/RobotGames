#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "Config.h"

class Encoder
{
public:
    void begin();

    long getLeftCount();
    long getRightCount();

    void resetLeft();
    void resetRight();
    void reset();

    float getLeftDistanceMM();
    float getRightDistanceMM();

    static void IRAM_ATTR leftISR_A();
    static void IRAM_ATTR rightISR_A();

private:
    static volatile long leftCount;
    static volatile long rightCount;
};

#endif