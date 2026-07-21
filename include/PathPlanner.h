#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include "Maze.h"

class PathPlanner
{
public:

    void begin(Maze *maze);

    Direction nextMove(uint8_t x,uint8_t y);

private:

    Maze *mazeMap;
};

#endif