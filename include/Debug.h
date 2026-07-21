#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

class Debug
{
public:

    void begin();

    void printSensors();

    void printEncoders();

    void printMaze();

    void printIMU();
};

#endif