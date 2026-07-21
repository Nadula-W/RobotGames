#include "EEPROMManager.h"

void EEPROMManager::begin()
{
    eeprom.begin();
}

void EEPROMManager::saveMaze(Maze* maze)
{
    uint32_t address = 0;

    for(int y=0;y<16;y++)
    {
        for(int x=0;x<16;x++)
        {
            uint8_t value = 0;

            if(maze->isVisited(x,y))
                value |= 0x01;

            if(maze->hasWall(x,y,NORTH))
                value |= 0x02;

            if(maze->hasWall(x,y,EAST))
                value |= 0x04;

            if(maze->hasWall(x,y,SOUTH))
                value |= 0x08;

            if(maze->hasWall(x,y,WEST))
                value |= 0x10;

            eeprom.writeByte(address++,value);
        }
    }
}

void EEPROMManager::loadMaze(Maze* maze)
{

}