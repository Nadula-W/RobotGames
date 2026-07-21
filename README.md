
1. Config Module (Config.h)

The Config module is the central configuration file for the robot. It stores all hardware-related definitions such as GPIO pin mappings, I2C addresses, and robot constants in one place, making the project easier to maintain and update.

Implemented:
• Motor driver pin definitions
• Encoder pin definitions
• IR sensor LED and ADC pin definitions
• I2C pin definitions
• Device addresses for MPU6050, EEPROM, and IO Expander

------------------------------------------------------------

2. Motor Module (Motor.h / Motor.cpp)

The Motor module controls both DC motors through the TB6612FNG motor driver.

Purpose:
Convert movement commands into actual wheel movement.

Functions Implemented:

• begin()
  Initializes all motor control pins and enables the motor driver.

• setLeftMotor(int speed)
  Controls the left motor.
  Positive speed moves forward, negative speed moves backward, and zero stops the motor.

• setRightMotor(int speed)
  Controls the right motor using the same logic.

• setMotorSpeed(int leftSpeed, int rightSpeed)
  Controls both motors simultaneously.

• stop()
  Stops both motors.

• brake()
  Applies electronic braking for faster stopping.

Features:
✔ PWM speed control
✔ Forward and reverse movement
✔ Brake mode
✔ Independent wheel control

------------------------------------------------------------

3. Encoder Module (Encoder.h / Encoder.cpp)

The Encoder module measures wheel rotation using the Hall-effect encoders attached to both motors.

Purpose:
Track wheel movement accurately for distance measurement and motion control.

Functions Implemented:

• begin()
  Configures encoder pins and attaches interrupts.

• leftISR_A()
  Interrupt routine that updates the left encoder count.

• rightISR_A()
  Interrupt routine that updates the right encoder count.

• getLeftCount()
  Returns the left encoder tick count.

• getRightCount()
  Returns the right encoder tick count.

• resetLeft()
  Resets the left encoder.

• resetRight()
  Resets the right encoder.

• reset()
  Resets both encoder counters.

• getLeftDistanceMM()
  Converts left encoder ticks into millimeters.

• getRightDistanceMM()
  Converts right encoder ticks into millimeters.

Features:
✔ Interrupt-driven counting
✔ Distance calculation
✔ Accurate wheel tracking
✔ Ready for PID and odometry

------------------------------------------------------------

4. IR Sensor Module (IRSensor.h / IRSensor.cpp)

The IR Sensor module reads six TCRT5000 infrared sensors used for wall detection.

Purpose:
Detect walls around the robot for navigation.

Functions Implemented:

• begin()
  Initializes IR LEDs and ADC.

• readSensor()
  Internal helper function that turns on an IR LED, reads the sensor, turns the LED off, and returns the ADC value.

Individual sensor functions:
• readLeftFront()
• readLeftDiagonal()
• readFrontLeft()
• readFrontRight()
• readRightDiagonal()
• readRightFront()

• readAll()
  Reads all six sensors sequentially.

Getter functions:
• getLeftFront()
• getLeftDiagonal()
• getFrontLeft()
• getFrontRight()
• getRightDiagonal()
• getRightFront()

Features:
✔ Six independent wall sensors
✔ Individual and bulk sensor reading
✔ Cached sensor values
✔ 12-bit ADC support

------------------------------------------------------------

5. MPU6050 Module (MPU6050.h / MPU6050.cpp)

The MPU6050 module provides motion sensing using a 3-axis accelerometer and 3-axis gyroscope.

Purpose:
Measure acceleration and rotational movement.

Functions Implemented:

• begin()
  Initializes I2C communication and wakes the MPU6050.

• update()
  Reads all accelerometer and gyroscope values.

Accelerometer getters:
• getAccelX()
• getAccelY()
• getAccelZ()

Gyroscope getters:
• getGyroX()
• getGyroY()
• getGyroZ()

Features:
✔ Accelerometer reading
✔ Gyroscope reading
✔ Floating-point conversion
✔ Ready for turn control and sensor fusion

------------------------------------------------------------

6. EEPROM Driver (EEPROM24C1024.h / EEPROM24C1024.cpp)

The EEPROM module provides permanent storage using the external AT24C1024 EEPROM.

Purpose:
Store robot data that must persist even after power is turned off, such as calibration values, explored maze data, and shortest paths.

Functions Implemented:

• begin()
  Initializes EEPROM communication over I2C.

• writeByte(uint32_t address, uint8_t data)
  Writes a single byte to the specified EEPROM address.

• readByte(uint32_t address)
  Reads a single byte from EEPROM.

• writeBlock(uint32_t address, const uint8_t *data, uint16_t length)
  Writes multiple bytes sequentially.

• readBlock(uint32_t address, uint8_t *buffer, uint16_t length)
  Reads multiple bytes sequentially.

Features:
✔ Single-byte read/write
✔ Multi-byte read/write
✔ Automatic EEPROM bank selection (0x50 / 0x51)
✔ Persistent storage support

------------------------------------------------------------

7. PID Controller (PID.h / PID.cpp)

The PID module implements a Proportional-Integral-Derivative controller used for precise closed-loop control.

Purpose:
Continuously reduce the error between the desired value and the measured value by adjusting the motor output.

Functions Implemented:

• PID()
  Constructor that initializes controller variables.

• setTunings(float kp, float ki, float kd)
  Sets the proportional, integral, and derivative gains.

• setOutputLimits(float min, float max)
  Limits the controller output to a specified range.

• reset()
  Clears the accumulated integral and previous error values.

• compute(float setpoint, float input)
  Calculates the PID output using the current error, accumulated integral, and derivative.

Features:
✔ Proportional control
✔ Integral control
✔ Derivative control
✔ Output limiting
✔ Controller reset
✔ Ready for speed control and wall following
