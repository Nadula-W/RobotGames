#ifndef EEPROM24C1024_H
#define EEPROM24C1024_H

#include <Arduino.h>
#include <Wire.h>
#include "Config.h"

class EEPROM24C1024
{
public:
    bool begin();

    void writeByte(uint32_t address, uint8_t data);
    uint8_t readByte(uint32_t address);

    void writeBlock(uint32_t address, const uint8_t *data, uint16_t length);
    void readBlock(uint32_t address, uint8_t *buffer, uint16_t length);

private:
    uint8_t deviceAddress(uint32_t address);
};

#endif