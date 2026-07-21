#ifndef EEPROMMANAGER_H
#define EEPROMMANAGER_H

#include "Maze.h"
#include "EEPROM24C1024.h"

class EEPROMManager
{
public:

    void begin();

    void saveMaze(Maze* maze);

    void loadMaze(Maze* maze);

private:

    EEPROM24C1024 eeprom;
};

#endif