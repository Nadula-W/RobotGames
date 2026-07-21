#include "Encoder.h"

volatile long Encoder::leftCount = 0;
volatile long Encoder::rightCount = 0;

constexpr float WHEEL_DIAMETER_MM = 32.0f;
constexpr int ENCODER_PPR = 390;

void Encoder::begin()
{
    pinMode(LEFT_ENC_A, INPUT_PULLUP);
    pinMode(LEFT_ENC_B, INPUT_PULLUP);

    pinMode(RIGHT_ENC_A, INPUT_PULLUP);
    pinMode(RIGHT_ENC_B, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(LEFT_ENC_A), leftISR_A, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENC_A), rightISR_A, CHANGE);
}

void IRAM_ATTR Encoder::leftISR_A()
{
    if (digitalRead(LEFT_ENC_A) == digitalRead(LEFT_ENC_B))
        leftCount++;
    else
        leftCount--;
}

void IRAM_ATTR Encoder::rightISR_A()
{
    if (digitalRead(RIGHT_ENC_A) == digitalRead(RIGHT_ENC_B))
        rightCount++;
    else
        rightCount--;
}

long Encoder::getLeftCount()
{
    return leftCount;
}

long Encoder::getRightCount()
{
    return rightCount;
}

void Encoder::resetLeft()
{
    leftCount = 0;
}

void Encoder::resetRight()
{
    rightCount = 0;
}

void Encoder::reset()
{
    leftCount = 0;
    rightCount = 0;
}

float Encoder::getLeftDistanceMM()
{
    return (leftCount * PI * WHEEL_DIAMETER_MM) / ENCODER_PPR;
}

float Encoder::getRightDistanceMM()
{
    return (rightCount * PI * WHEEL_DIAMETER_MM) / ENCODER_PPR;
}