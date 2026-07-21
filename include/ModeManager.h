#ifndef MODEMANAGER_H
#define MODEMANAGER_H

#include <Arduino.h>

enum RobotMode
{
    MODE_IDLE = 0,
    MODE_CALIBRATION,
    MODE_DEBUG,
    MODE_EXPLORE,
    MODE_FAST_RUN,
    MODE_RETURN_HOME
};

class ModeManager
{
public:

    void begin();

    void update();

    void setMode(RobotMode mode);

    RobotMode getMode();

private:

    RobotMode currentMode;
};

#endif