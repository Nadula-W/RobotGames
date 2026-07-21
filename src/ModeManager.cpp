#include "ModeManager.h"

void ModeManager::begin()
{
    currentMode = MODE_IDLE;
}

void ModeManager::update()
{

}

void ModeManager::setMode(RobotMode mode)
{
    currentMode = mode;
}

RobotMode ModeManager::getMode()
{
    return currentMode;
}