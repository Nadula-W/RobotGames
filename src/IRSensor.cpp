#include "IRSensor.h"

void IRSensor::begin()
{
    analogReadResolution(12);

    pinMode(IR_LED_1, OUTPUT);
    pinMode(IR_LED_2, OUTPUT);
    pinMode(IR_LED_3, OUTPUT);
    pinMode(IR_LED_4, OUTPUT);
    pinMode(IR_LED_5, OUTPUT);
    pinMode(IR_LED_6, OUTPUT);

    digitalWrite(IR_LED_1, LOW);
    digitalWrite(IR_LED_2, LOW);
    digitalWrite(IR_LED_3, LOW);
    digitalWrite(IR_LED_4, LOW);
    digitalWrite(IR_LED_5, LOW);
    digitalWrite(IR_LED_6, LOW);
}

uint16_t IRSensor::readSensor(uint8_t ledPin, uint8_t adcPin)
{
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(150);

    uint16_t value = analogRead(adcPin);

    digitalWrite(ledPin, LOW);

    return value;
}

uint16_t IRSensor::readLeftFront()
{
    leftFront = readSensor(IR_LED_1, IR_LEFT_FRONT);
    return leftFront;
}

uint16_t IRSensor::readLeftDiagonal()
{
    leftDiagonal = readSensor(IR_LED_2, IR_LEFT_DIAGONAL);
    return leftDiagonal;
}

uint16_t IRSensor::readFrontLeft()
{
    frontLeft = readSensor(IR_LED_3, IR_FRONT_LEFT);
    return frontLeft;
}

uint16_t IRSensor::readFrontRight()
{
    frontRight = readSensor(IR_LED_4, IR_FRONT_RIGHT);
    return frontRight;
}

uint16_t IRSensor::readRightDiagonal()
{
    rightDiagonal = readSensor(IR_LED_5, IR_RIGHT_DIAGONAL);
    return rightDiagonal;
}

uint16_t IRSensor::readRightFront()
{
    rightFront = readSensor(IR_LED_6, IR_RIGHT_FRONT);
    return rightFront;
}

void IRSensor::readAll()
{
    readLeftFront();
    readLeftDiagonal();
    readFrontLeft();
    readFrontRight();
    readRightDiagonal();
    readRightFront();
}

uint16_t IRSensor::getLeftFront()
{
    return leftFront;
}

uint16_t IRSensor::getLeftDiagonal()
{
    return leftDiagonal;
}

uint16_t IRSensor::getFrontLeft()
{
    return frontLeft;
}

uint16_t IRSensor::getFrontRight()
{
    return frontRight;
}

uint16_t IRSensor::getRightDiagonal()
{
    return rightDiagonal;
}

uint16_t IRSensor::getRightFront()
{
    return rightFront;
}