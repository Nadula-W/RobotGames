#include "WallDetection.h"
#include "IRSensor.h"

extern IRSensor ir;

void WallDetection::begin()
{
    threshold=350;
}

void WallDetection::update()
{
    ir.readAll();

    left=
        (ir.getLeftFront()+
        ir.getLeftDiagonal())/2;

    front=
        (ir.getFrontLeft()+
        ir.getFrontRight())/2;

    right=
        (ir.getRightFront()+
        ir.getRightDiagonal())/2;
}

bool WallDetection::leftWall()
{
    return left>threshold;
}

bool WallDetection::frontWall()
{
    return front>threshold;
}

bool WallDetection::rightWall()
{
    return right>threshold;
}

uint16_t WallDetection::leftDistance()
{
    return left;
}

uint16_t WallDetection::frontDistance()
{
    return front;
}

uint16_t WallDetection::rightDistance()
{
    return right;
}

void WallDetection::setThreshold(uint16_t t)
{
    threshold=t;
}