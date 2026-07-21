#include "EEPROM24C1024.h"

bool EEPROM24C1024::begin()
{
    Wire.begin(I2C_SDA, I2C_SCL);
    return true;
}

uint8_t EEPROM24C1024::deviceAddress(uint32_t address)
{
    if(address < 65536)
        return 0x50;

    return 0x51;
}

void EEPROM24C1024::writeByte(uint32_t address, uint8_t data)
{
    uint8_t dev = deviceAddress(address);
    uint16_t mem = address & 0xFFFF;

    Wire.beginTransmission(dev);
    Wire.write(mem >> 8);
    Wire.write(mem & 0xFF);
    Wire.write(data);
    Wire.endTransmission();

    delay(5);
}

uint8_t EEPROM24C1024::readByte(uint32_t address)
{
    uint8_t dev = deviceAddress(address);
    uint16_t mem = address & 0xFFFF;

    Wire.beginTransmission(dev);
    Wire.write(mem >> 8);
    Wire.write(mem & 0xFF);
    Wire.endTransmission(false);

    Wire.requestFrom(dev, (uint8_t)1);

    if(Wire.available())
        return Wire.read();

    return 0;
}

void EEPROM24C1024::writeBlock(uint32_t address, const uint8_t *data, uint16_t length)
{
    for(uint16_t i=0;i<length;i++)
        writeByte(address+i,data[i]);
}

void EEPROM24C1024::readBlock(uint32_t address, uint8_t *buffer, uint16_t length)
{
    for(uint16_t i=0;i<length;i++)
        buffer[i]=readByte(address+i);
}