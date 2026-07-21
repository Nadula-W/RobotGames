#include "Maze.h"

void Maze::begin()
{
    reset();
}

void Maze::reset()
{
    for(int y=0;y<MAZE_SIZE;y++)
    {
        for(int x=0;x<MAZE_SIZE;x++)
        {
            maze[y][x].visited=false;

            maze[y][x].northWall=false;
            maze[y][x].eastWall=false;
            maze[y][x].southWall=false;
            maze[y][x].westWall=false;

            maze[y][x].cost=255;
        }
    }
}

bool Maze::isVisited(uint8_t x,uint8_t y)
{
    return maze[y][x].visited;
}

void Maze::setVisited(uint8_t x,uint8_t y)
{
    maze[y][x].visited=true;
}

void Maze::setWall(uint8_t x,uint8_t y,Direction dir,bool wall)
{
    switch(dir)
    {
        case NORTH:
            maze[y][x].northWall=wall;
            break;

        case EAST:
            maze[y][x].eastWall=wall;
            break;

        case SOUTH:
            maze[y][x].southWall=wall;
            break;

        case WEST:
            maze[y][x].westWall=wall;
            break;
    }
}

bool Maze::hasWall(uint8_t x,uint8_t y,Direction dir)
{
    switch(dir)
    {
        case NORTH:
            return maze[y][x].northWall;

        case EAST:
            return maze[y][x].eastWall;

        case SOUTH:
            return maze[y][x].southWall;

        case WEST:
            return maze[y][x].westWall;
    }

    return false;
}

void Maze::setCost(uint8_t x,uint8_t y,uint8_t cost)
{
    maze[y][x].cost=cost;
}

uint8_t Maze::getCost(uint8_t x,uint8_t y)
{
    return maze[y][x].cost;
}