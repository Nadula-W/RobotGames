#ifndef MPU6050_H
#define MPU6050_H

#include <Arduino.h>
#include <Wire.h>
#include "Config.h"

class MPU6050Sensor
{
public:
    bool begin();

    void update();

    float getAccelX();
    float getAccelY();
    float getAccelZ();

    float getGyroX();
    float getGyroY();
    float getGyroZ();

private:
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
};

#endif