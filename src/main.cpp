#include <Arduino.h>
#include "Config.h"
#include "Motor.h"
#include "Encoder.h"

Motor motor;
Encoder encoder;

void setup()
{
    Serial.begin(115200);

    motor.begin();
    encoder.begin();

    Serial.println("Robot Initialized");
}

void loop()
{
    Serial.print("Left: ");
    Serial.print(encoder.getLeftCount());

    Serial.print(" | Right: ");
    Serial.println(encoder.getRightCount());

    delay(200);
}
