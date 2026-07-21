#ifndef EXPLORATION_H
#define EXPLORATION_H

#include "Maze.h"
#include "WallDetection.h"
#include "MotionController.h"

class Exploration
{
public:

    void begin(
        Maze* maze,
        WallDetection* walls,
        MotionController* motion);

    void update();

private:

    Maze* mazeMap;

    WallDetection* wallSensor;

    MotionController* motionController;

    uint8_t x;
    uint8_t y;

    Direction heading;

    void updateWalls();

    void moveNextCell();
};

#endif