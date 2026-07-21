#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "Config.h"

class Motor
{
public:
    void begin();

    void forward(uint8_t speed);
    void backward(uint8_t speed);

    void turnLeft(uint8_t speed);
    void turnRight(uint8_t speed);

    void setLeftMotor(int speed);
    void setRightMotor(int speed);
    void setMotorSpeed(int leftSpeed, int rightSpeed);

    void stop();

private:
    static constexpr uint32_t PWM_FREQUENCY = 20000; // 20 kHz
    static constexpr uint8_t PWM_RESOLUTION = 8;     // 8-bit (0-255)
};

#endif