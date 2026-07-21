#include "PathPlanner.h"

void PathPlanner::begin(Maze *maze)
{
    mazeMap=maze;
}

Direction PathPlanner::nextMove(uint8_t x,uint8_t y)
{
    uint8_t best=255;

    Direction direction=NORTH;

    if(y>0)
    {
        if(!mazeMap->hasWall(x,y,NORTH))
        {
            if(mazeMap->getCost(x,y-1)<best)
            {
                best=mazeMap->getCost(x,y-1);
                direction=NORTH;
            }
        }
    }

    if(x<15)
    {
        if(!mazeMap->hasWall(x,y,EAST))
        {
            if(mazeMap->getCost(x+1,y)<best)
            {
                best=mazeMap->getCost(x+1,y);
                direction=EAST;
            }
        }
    }

    if(y<15)
    {
        if(!mazeMap->hasWall(x,y,SOUTH))
        {
            if(mazeMap->getCost(x,y+1)<best)
            {
                best=mazeMap->getCost(x,y+1);
                direction=SOUTH;
            }
        }
    }

    if(x>0)
    {
        if(!mazeMap->hasWall(x,y,WEST))
        {
            if(mazeMap->getCost(x-1,y)<best)
            {
                best=mazeMap->getCost(x-1,y);
                direction=WEST;
            }
        }
    }

    return direction;
}