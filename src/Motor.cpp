#include "Motor.h"

void Motor::begin()
{
    pinMode(MOTOR_STBY, OUTPUT);

    pinMode(LEFT_IN1, OUTPUT);
    pinMode(LEFT_IN2, OUTPUT);

    pinMode(RIGHT_IN1, OUTPUT);
    pinMode(RIGHT_IN2, OUTPUT);

    // Configure PWM
    ledcSetup(LEFT_PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(LEFT_PWM, LEFT_PWM_CHANNEL);

    ledcSetup(RIGHT_PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(RIGHT_PWM, RIGHT_PWM_CHANNEL);

    // Enable motor driver
    digitalWrite(MOTOR_STBY, HIGH);

    stop();
}

void Motor::setLeftMotor(int speed)
{
    speed = constrain(speed, -255, 255);

    if (speed > 0)
    {
        digitalWrite(LEFT_IN1, HIGH);
        digitalWrite(LEFT_IN2, LOW);
        ledcWrite(LEFT_PWM_CHANNEL, speed);
    }
    else if (speed < 0)
    {
        digitalWrite(LEFT_IN1, LOW);
        digitalWrite(LEFT_IN2, HIGH);
        ledcWrite(LEFT_PWM_CHANNEL, -speed);
    }
    else
    {
        digitalWrite(LEFT_IN1, LOW);
        digitalWrite(LEFT_IN2, LOW);
        ledcWrite(LEFT_PWM_CHANNEL, 0);
    }
}

void Motor::setRightMotor(int speed)
{
    speed = constrain(speed, -255, 255);

    if (speed > 0)
    {
        digitalWrite(RIGHT_IN1, HIGH);
        digitalWrite(RIGHT_IN2, LOW);
        ledcWrite(RIGHT_PWM_CHANNEL, speed);
    }
    else if (speed < 0)
    {
        digitalWrite(RIGHT_IN1, LOW);
        digitalWrite(RIGHT_IN2, HIGH);
        ledcWrite(RIGHT_PWM_CHANNEL, -speed);
    }
    else
    {
        digitalWrite(RIGHT_IN1, LOW);
        digitalWrite(RIGHT_IN2, LOW);
        ledcWrite(RIGHT_PWM_CHANNEL, 0);
    }
}

void Motor::forward(uint8_t speed)
{
    setLeftMotor(speed);
    setRightMotor(speed);
}

void Motor::backward(uint8_t speed)
{
    setLeftMotor(-speed);
    setRightMotor(-speed);
}

void Motor::turnLeft(uint8_t speed)
{
    setLeftMotor(-speed);
    setRightMotor(speed);
}

void Motor::turnRight(uint8_t speed)
{
    setLeftMotor(speed);
    setRightMotor(-speed);
}

void Motor::stop()
{
    setLeftMotor(0);
    setRightMotor(0);
}
void Motor::setMotorSpeed(int leftSpeed, int rightSpeed)
{
    setLeftMotor(leftSpeed);
    setRightMotor(rightSpeed);
}