#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID
{
public:
    PID();

    void setTunings(float kp,float ki,float kd);

    void setOutputLimits(float min,float max);

    void reset();

    float compute(float setpoint,float input);

private:

    float Kp;
    float Ki;
    float Kd;

    float integral;
    float previousError;

    float outputMin;
    float outputMax;

    unsigned long previousTime;
};

#endif