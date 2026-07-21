#ifndef MAZE_H
#define MAZE_H

#include <Arduino.h>

#define MAZE_SIZE 16

enum Direction
{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
};

struct Cell
{
    bool visited;

    bool northWall;
    bool eastWall;
    bool southWall;
    bool westWall;

    uint8_t cost;
};

class Maze
{
public:

    void begin();

    void reset();

    bool isVisited(uint8_t x,uint8_t y);

    void setVisited(uint8_t x,uint8_t y);

    void setWall(uint8_t x,uint8_t y,Direction dir,bool wall);

    bool hasWall(uint8_t x,uint8_t y,Direction dir);

    void setCost(uint8_t x,uint8_t y,uint8_t cost);

    uint8_t getCost(uint8_t x,uint8_t y);

private:

    Cell maze[MAZE_SIZE][MAZE_SIZE];
};

#endif