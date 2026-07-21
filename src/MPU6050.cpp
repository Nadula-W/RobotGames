#include "MPU6050.h"

bool MPU6050Sensor::begin()
{
    Wire.begin(I2C_SDA, I2C_SCL);

    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(0x6B);
    Wire.write(0);
    if (Wire.endTransmission() != 0)
        return false;

    return true;
}

void MPU6050Sensor::update()
{
    Wire.beginTransmission(MPU6050_ADDRESS);
    Wire.write(0x3B);
    Wire.endTransmission(false);

    Wire.requestFrom((uint8_t)MPU6050_ADDRESS, (uint8_t)14);

    ax = (Wire.read() << 8) | Wire.read();
    ay = (Wire.read() << 8) | Wire.read();
    az = (Wire.read() << 8) | Wire.read();

    Wire.read();
    Wire.read();

    gx = (Wire.read() << 8) | Wire.read();
    gy = (Wire.read() << 8) | Wire.read();
    gz = (Wire.read() << 8) | Wire.read();
}

float MPU6050Sensor::getAccelX()
{
    return ax / 16384.0f;
}

float MPU6050Sensor::getAccelY()
{
    return ay / 16384.0f;
}

float MPU6050Sensor::getAccelZ()
{
    return az / 16384.0f;
}

float MPU6050Sensor::getGyroX()
{
    return gx / 131.0f;
}

float MPU6050Sensor::getGyroY()
{
    return gy / 131.0f;
}

float MPU6050Sensor::getGyroZ()
{
    return gz / 131.0f;
}