#ifndef WALLDETECTION_H
#define WALLDETECTION_H

#include <Arduino.h>

class WallDetection
{
public:

    void begin();

    void update();

    bool leftWall();

    bool frontWall();

    bool rightWall();

    uint16_t leftDistance();

    uint16_t frontDistance();

    uint16_t rightDistance();

    void setThreshold(uint16_t threshold);

private:

    uint16_t threshold;

    uint16_t left;
    uint16_t front;
    uint16_t right;
};

#endif