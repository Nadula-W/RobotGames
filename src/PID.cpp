#include "PID.h"

PID::PID()
{
    Kp=0;
    Ki=0;
    Kd=0;

    integral=0;
    previousError=0;

    outputMin=-255;
    outputMax=255;

    previousTime=millis();
}

void PID::setTunings(float kp,float ki,float kd)
{
    Kp=kp;
    Ki=ki;
    Kd=kd;
}

void PID::setOutputLimits(float min,float max)
{
    outputMin=min;
    outputMax=max;
}

void PID::reset()
{
    integral=0;
    previousError=0;
    previousTime=millis();
}

float PID::compute(float setpoint,float input)
{
    unsigned long now=millis();

    float dt=(now-previousTime)/1000.0f;

    previousTime=now;

    if(dt<=0)
        dt=0.001f;

    float error=setpoint-input;

    integral+=error*dt;

    float derivative=(error-previousError)/dt;

    previousError=error;

    float output=
        Kp*error+
        Ki*integral+
        Kd*derivative;

    if(output>outputMax)
        output=outputMax;

    if(output<outputMin)
        output=outputMin;

    return output;
}