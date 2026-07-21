Current Progress

1. Config Module (Config.h)

The Config module is the central configuration file for the entire robot. Instead of hardcoding GPIO numbers and hardware constants throughout the project, everything is defined in one place.

Purpose:
- Store all GPIO pin definitions.
- Store I2C addresses.
- Store hardware-related constants.
- Make the project easy to maintain if hardware changes.

Contains:
• Motor driver pins
  - PWMA
  - PWMB
  - AIN1
  - AIN2
  - BIN1
  - BIN2
  - STBY

• Encoder pins
  - LEFT_ENC_A
  - LEFT_ENC_B
  - RIGHT_ENC_A
  - RIGHT_ENC_B

• IR sensor LED pins
  - IR_LED_1 → IR_LED_6

• IR sensor ADC pins
  - IR_LEFT_FRONT
  - IR_LEFT_DIAGONAL
  - IR_FRONT_LEFT
  - IR_FRONT_RIGHT
  - IR_RIGHT_DIAGONAL
  - IR_RIGHT_FRONT

• I2C pins
  - SDA
  - SCL

• Device addresses
  - MPU6050
  - EEPROM
  - IO Expander



------------------------------------------------------------

2. Motor Module (Motor.h / Motor.cpp)

The Motor module is responsible for controlling both DC motors through the TB6612FNG motor driver.

Purpose:
Convert movement commands into actual wheel movement.

Functions Implemented:

• begin()
  Initializes all motor pins and enables the motor driver.

• setLeftMotor(int speed)
  Controls the left motor.
  - Positive value → Forward
  - Negative value → Reverse
  - Zero → Stop

• setRightMotor(int speed)
  Controls the right motor.

• setMotorSpeed(int left, int right)
  Controls both motors simultaneously.

Examples:
Forward:
left = 120
right = 120

Backward:
left = -120
right = -120

Turn Left:
left = -120
right = 120

Turn Right:
left = 120
right = -120

• stop()
  Stops both motors.

• brake()
  Electronically brakes both motors for a faster stop.

Features:
✔ PWM speed control
✔ Forward & Reverse
✔ Brake mode
✔ Independent wheel control
✔ TB6612FNG support



------------------------------------------------------------

3. Encoder Module (Encoder.h / Encoder.cpp)

The Encoder module tracks how much each wheel has rotated using the Hall effect encoders attached to the motors.

Purpose:
Measure wheel movement accurately.

The ESP32 counts encoder pulses using interrupts.

Functions Implemented:

• begin()
  Configures encoder pins.
  Attaches hardware interrupts.

• leftISR_A()
  Interrupt routine that updates the left encoder count whenever a pulse occurs.

• rightISR_A()
  Interrupt routine that updates the right encoder count.

• getLeftCount()
  Returns current left encoder ticks.

• getRightCount()
  Returns current right encoder ticks.

• resetLeft()
  Resets left encoder count.

• resetRight()
  Resets right encoder count.

• reset()
  Resets both encoder counters.

• getLeftDistanceMM()
  Converts left encoder ticks into millimeters travelled.

• getRightDistanceMM()
  Converts right encoder ticks into millimeters travelled.

What this allows:
✔ Measure travelled distance
✔ Maintain straight movement
✔ Perform accurate turns
✔ Calculate wheel speed
✔ Future odometry support



------------------------------------------------------------

4. IR Sensor Module (IRSensor.h / IRSensor.cpp)

The IR Sensor module enables the robot to detect maze walls using six TCRT5000 infrared sensors.

Each sensor consists of:
- IR LED (Emitter)
- Phototransistor (Receiver)

The emitter sends infrared light.
If a wall is nearby, more light reflects back and the ADC value increases.

Functions Implemented:

• begin()
  Initializes all IR LEDs.
  Configures ADC resolution.

• readSensor()
  Internal helper function.
  Steps:
  1. Turn ON IR LED.
  2. Wait briefly.
  3. Read ADC.
  4. Turn OFF LED.
  5. Return sensor value.

Individual sensor reading functions:

• readLeftFront()
• readLeftDiagonal()
• readFrontLeft()
• readFrontRight()
• readRightDiagonal()
• readRightFront()

Each function updates the stored sensor value and returns the latest reading.

• readAll()
  Reads all six sensors sequentially.

Getter functions:

• getLeftFront()
• getLeftDiagonal()
• getFrontLeft()
• getFrontRight()
• getRightDiagonal()
• getRightFront()

These return the latest stored sensor values without performing another ADC conversion.

What this allows:
✔ Detect left walls
✔ Detect front walls
✔ Detect right walls
✔ Future wall following
✔ Future wall centering
✔ Future maze mapping



------------------------------------------------------------

5. MPU6050 Module (MPU6050.h / MPU6050.cpp)

The MPU6050 module provides motion sensing using a 3-axis accelerometer and a 3-axis gyroscope.

Purpose:
Measure acceleration and rotational movement of the robot.

Functions Implemented:

• begin()
  Initializes I2C communication.
  Wakes the MPU6050 from sleep mode.

• update()
  Reads:
  - Acceleration X
  - Acceleration Y
  - Acceleration Z
  - Gyroscope X
  - Gyroscope Y
  - Gyroscope Z

Accelerometer getter functions:

• getAccelX()
• getAccelY()
• getAccelZ()

Returns acceleration in g.

Gyroscope getter functions:

• getGyroX()
• getGyroY()
• getGyroZ()

Returns angular velocity in degrees/second.

What this allows:
✔ Detect robot rotation
✔ Improve turning accuracy
✔ Detect drift
✔ Future sensor fusion with encoders
✔ Better motion control



------------------------------------------------------------

6. Test Program (main.cpp)

Current functionality:

• Initializes Serial Monitor
• Initializes Motor module
• Initializes Encoder module
• Continuously prints:
  - Left encoder ticks
  - Right encoder ticks

Used for verifying that the encoder hardware and interrupts are functioning correctly before integrating PID and navigation.



------------------------------------------------------------

Overall Progress

Completed Modules:
✔ Config
✔ Motor Driver
✔ Encoder Driver
✔ IR Sensor Driver
✔ MPU6050 Driver

Next Modules:
- EEPROM Driver
- PID Controller
- Motion Controller
- Calibration
- Wall Detection
- Maze Representation
- Flood Fill Algorithm
- Path Planner
- Robot Core
- Mode Manager
- Competition Firmware