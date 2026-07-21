#include "FloodFill.h"

void FloodFill::begin(Maze *maze)
{
    mazeMap=maze;
}

void FloodFill::calculate()
{
    const uint8_t goalX1=7;
    const uint8_t goalY1=7;

    const uint8_t goalX2=8;
    const uint8_t goalY2=8;

    for(int y=0;y<MAZE_SIZE;y++)
    {
        for(int x=0;x<MAZE_SIZE;x++)
        {
            uint8_t cost=
                abs(goalX1-x)+
                abs(goalY1-y);

            uint8_t cost2=
                abs(goalX2-x)+
                abs(goalY2-y);

            if(cost2<cost)
                cost=cost2;

            mazeMap->setCost(x,y,cost);
        }
    }
}