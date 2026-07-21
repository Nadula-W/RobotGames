#include "MotionController.h"
#include "Motor.h"
#include "Encoder.h"

extern Motor motor;
extern Encoder encoder;

void MotionController::begin()
{
    speedPID.setTunings(2.0,0,0);
    speedPID.setOutputLimits(-50,50);

    baseSpeed=120;
}

void MotionController::setBaseSpeed(int speed)
{
    baseSpeed=speed;
}

void MotionController::moveForward()
{
    float correction=
        speedPID.compute(
            encoder.getLeftCount(),
            encoder.getRightCount());

    motor.setMotorSpeed(
        baseSpeed,
        baseSpeed+correction);
}

void MotionController::stop()
{
    motor.stop();
}

void MotionController::turnLeft()
{
    motor.setMotorSpeed(-baseSpeed,baseSpeed);
}

void MotionController::turnRight()
{
    motor.setMotorSpeed(baseSpeed,-baseSpeed);
}

void MotionController::turnAround()
{
    motor.setMotorSpeed(baseSpeed,-baseSpeed);
}

void MotionController::update()
{
    moveForward();
}