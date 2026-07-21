#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"
#include "FloodFill.h"
#include "PathPlanner.h"
#include "MotionController.h"
#include "WallDetection.h"

class Robot
{
public:

    void begin();

    void update();

private:

    Maze maze;

    FloodFill floodFill;

    PathPlanner planner;

    MotionController motion;

    WallDetection walls;

    uint8_t x;
    uint8_t y;

    Direction heading;
};

#endif