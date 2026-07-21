#include "Robot.h"

void Robot::begin()
{
    maze.begin();

    floodFill.begin(&maze);

    planner.begin(&maze);

    motion.begin();

    walls.begin();

    floodFill.calculate();

    x=0;
    y=15;

    heading=NORTH;
}

void Robot::update()
{
    walls.update();

    Direction next=
        planner.nextMove(x,y);

    switch(next)
    {
        case NORTH:
            motion.moveForward();
            break;

        case EAST:
            motion.turnRight();
            break;

        case SOUTH:
            motion.turnAround();
            break;

        case WEST:
            motion.turnLeft();
            break;
    }
}