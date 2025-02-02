#include <Arduino.h>
#include <Servo.h>

Servo clawServo;

void setup()
{
    clawServo.attach(2);
    clawServo.write(15);
}
void loop()
{
    clawServo.write(70);
    delay(1000);
    clawServo.write(15);
    delay(1000);
}