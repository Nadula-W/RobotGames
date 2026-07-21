#include "Debug.h"
#include "IRSensor.h"
#include "Encoder.h"
#include "MPU6050.h"

extern IRSensor ir;
extern Encoder encoder;
extern MPU6050Sensor imu;

void Debug::begin()
{
    Serial.begin(115200);
}

void Debug::printSensors()
{
    ir.readAll();

    Serial.print(ir.getLeftFront());
    Serial.print('\t');

    Serial.print(ir.getLeftDiagonal());
    Serial.print('\t');

    Serial.print(ir.getFrontLeft());
    Serial.print('\t');

    Serial.print(ir.getFrontRight());
    Serial.print('\t');

    Serial.print(ir.getRightDiagonal());
    Serial.print('\t');

    Serial.println(ir.getRightFront());
}

void Debug::printEncoders()
{
    Serial.print(encoder.getLeftCount());

    Serial.print('\t');

    Serial.println(encoder.getRightCount());
}

void Debug::printIMU()
{
    imu.update();

    Serial.print(imu.getGyroX());

    Serial.print('\t');

    Serial.print(imu.getGyroY());

    Serial.print('\t');

    Serial.println(imu.getGyroZ());
}

void Debug::printMaze()
{

}