#ifndef MOTIONCONTROLLER_H
#define MOTIONCONTROLLER_H

#include <Arduino.h>
#include "PID.h"

class MotionController
{
public:

    void begin();

    void setBaseSpeed(int speed);

    void moveForward();

    void stop();

    void turnLeft();

    void turnRight();

    void turnAround();

    void update();

private:

    PID speedPID;

    int baseSpeed;
};

#endif