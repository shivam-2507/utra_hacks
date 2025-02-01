#include <Arduino.h>

// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Calibration Values from the previous sketch
int redMin = 20;  // Example calibration minimum
int redMax = 700; // Example calibration maximum
int greenMin = 30;
int greenMax = 700;
int blueMin = 25;
int blueMax = 650;

int redValue, greenValue, blueValue;

int readColorPulseWidth(bool s2State, bool s3State)
{
    digitalWrite(S2, s2State);
    digitalWrite(S3, s3State);
    return pulseIn(sensorOut, LOW);
}

void setup()
{
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    Serial.begin(9600);
}

void loop()
{
    redValue = map(readColorPulseWidth(LOW, LOW), redMin, redMax, 255, 0);
    greenValue = map(readColorPulseWidth(HIGH, HIGH), greenMin, greenMax, 255, 0);
    blueValue = map(readColorPulseWidth(LOW, HIGH), blueMin, blueMax, 255, 0);

    Serial.print("R: ");
    Serial.print(redValue);
    Serial.print(" G: ");
    Serial.print(greenValue);
    Serial.print(" B: ");
    Serial.println(blueValue);

    delay(500);
}
