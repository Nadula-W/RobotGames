#include "Calibration.h"
#include "IRSensor.h"

extern IRSensor ir;

Calibration::Calibration()
{
    finished = false;
}

void Calibration::begin()
{
    for(int i=0;i<6;i++)
    {
        minValue[i]=4095;
        maxValue[i]=0;
    }
}

void Calibration::start()
{
    finished=false;

    for(int i=0;i<6;i++)
    {
        minValue[i]=4095;
        maxValue[i]=0;
    }
}

void Calibration::update()
{
    ir.readAll();

    uint16_t value[6]=
    {
        ir.getLeftFront(),
        ir.getLeftDiagonal(),
        ir.getFrontLeft(),
        ir.getFrontRight(),
        ir.getRightDiagonal(),
        ir.getRightFront()
    };

    for(int i=0;i<6;i++)
    {
        if(value[i]<minValue[i])
            minValue[i]=value[i];

        if(value[i]>maxValue[i])
            maxValue[i]=value[i];
    }
}

bool Calibration::isFinished()
{
    return finished;
}

uint16_t Calibration::getMin(uint8_t sensor)
{
    return minValue[sensor];
}

uint16_t Calibration::getMax(uint8_t sensor)
{
    return maxValue[sensor];
}

uint16_t Calibration::normalize(uint8_t sensor,uint16_t value)
{
    if(maxValue[sensor]==minValue[sensor])
        return 0;

    return map(value,
               minValue[sensor],
               maxValue[sensor],
               0,
               1000);
}