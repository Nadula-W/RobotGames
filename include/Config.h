#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

/*==================================================
    ROBOT INFORMATION
==================================================*/

#define ROBOT_NAME         "MicroMazeBot"
#define FIRMWARE_VERSION   "1.0.0"

/*==================================================
    IR SENSOR PINS (ADC)
==================================================*/

constexpr uint8_t IR_LEFT_FRONT      = 1;
constexpr uint8_t IR_LEFT_DIAGONAL   = 2;
constexpr uint8_t IR_FRONT_LEFT      = 42;
constexpr uint8_t IR_FRONT_RIGHT     = 16;
constexpr uint8_t IR_RIGHT_DIAGONAL  = 17;
constexpr uint8_t IR_RIGHT_FRONT     = 18;

/*==================================================
    IR LED DRIVER PINS
==================================================*/

constexpr uint8_t IR_LED_1 = 3;
constexpr uint8_t IR_LED_2 = 4;
constexpr uint8_t IR_LED_3 = 5;
constexpr uint8_t IR_LED_4 = 6;
constexpr uint8_t IR_LED_5 = 7;
constexpr uint8_t IR_LED_6 = 15;

/*==================================================
    MOTOR DRIVER (TB6612FNG)
==================================================*/

constexpr uint8_t MOTOR_STBY = 14;

constexpr uint8_t LEFT_PWM_CHANNEL  = 0;
constexpr uint8_t RIGHT_PWM_CHANNEL = 1;
// Left Motor
constexpr uint8_t LEFT_PWM = 11;
constexpr uint8_t LEFT_IN1 = 13;
constexpr uint8_t LEFT_IN2 = 12;

// Right Motor
constexpr uint8_t RIGHT_PWM = 48;
constexpr uint8_t RIGHT_IN1 = 21;
constexpr uint8_t RIGHT_IN2 = 47;

/*==================================================
    ENCODERS
==================================================*/

// Left Encoder
constexpr uint8_t LEFT_ENC_A = 40;
constexpr uint8_t LEFT_ENC_B = 41;

// Right Encoder
constexpr uint8_t RIGHT_ENC_A = 39;
constexpr uint8_t RIGHT_ENC_B = 38;

/*==================================================
    I2C
==================================================*/

constexpr uint8_t I2C_SDA = 8;
constexpr uint8_t I2C_SCL = 9;

/*==================================================
    EEPROM
==================================================*/

constexpr uint8_t EEPROM_WE = 10;

constexpr uint8_t EEPROM_ADDRESS_LOW  = 0x50;
constexpr uint8_t EEPROM_ADDRESS_HIGH = 0x51;

/*==================================================
    MPU6050
==================================================*/

constexpr uint8_t MPU6050_ADDRESS = 0x68;

/*==================================================
    IO EXPANDER
==================================================*/

constexpr uint8_t PCF8574_ADDRESS = 0x38;
constexpr uint8_t IO_INTERRUPT    = 0;

/*==================================================
    RGB LED
==================================================*/

constexpr uint8_t RGB_LED = 46;

/*==================================================
    ROBOT PARAMETERS
==================================================*/

constexpr float CELL_SIZE = 180.0f;       // mm
constexpr float WALL_THICKNESS = 12.0f;   // mm

constexpr uint8_t MAZE_ROWS = 16;
constexpr uint8_t MAZE_COLS = 16;

/*==================================================
    MOTOR PARAMETERS
==================================================*/

constexpr int MAX_PWM = 255;
constexpr int DEFAULT_SPEED = 120;
constexpr int TURN_SPEED = 100;

/*==================================================
    PID DEFAULTS
==================================================*/

constexpr float KP = 0.80f;
constexpr float KI = 0.00f;
constexpr float KD = 8.00f;

#endif