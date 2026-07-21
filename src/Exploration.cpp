#include "Exploration.h"

void Exploration::begin(
    Maze* maze,
    WallDetection* walls,
    MotionController* motion)
{
    mazeMap = maze;

    wallSensor = walls;

    motionController = motion;

    x = 0;
    y = 15;

    heading = NORTH;
}

void Exploration::update()
{
    wallSensor->update();

    updateWalls();

    moveNextCell();
}

void Exploration::updateWalls()
{
    mazeMap->setVisited(x,y);

    mazeMap->setWall(
        x,
        y,
        heading,
        wallSensor->frontWall());

    mazeMap->setWall(
        x,
        y,
        (Direction)((heading+3)%4),
        wallSensor->leftWall());

    mazeMap->setWall(
        x,
        y,
        (Direction)((heading+1)%4),
        wallSensor->rightWall());
}

void Exploration::moveNextCell()
{
    motionController->moveForward();
}