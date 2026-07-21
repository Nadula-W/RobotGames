#ifndef FLOODFILL_H
#define FLOODFILL_H

#include "Maze.h"

class FloodFill
{
public:

    void begin(Maze *maze);

    void calculate();

private:

    Maze *mazeMap;
};

#endif