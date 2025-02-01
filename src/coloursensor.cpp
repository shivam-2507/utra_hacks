#include <Arduino.h>

// Define TCS230 pins
const int S0 = 4;
const int S1 = 5;
const int S2 = 6;
const int S3 = 7;
const int sensorOut = 8;

unsigned long redFrequency, greenFrequency, blueFrequency;

int mapFrequencyToRGB(unsigned long frequency)
{
    // Map frequencies to RGB range (0-255)
    frequency = constrain(frequency, 500, 60000); // Define frequency limits
    return map(frequency, 60000, 500, 0, 255);
}

void setup()
{
    // Pin setup
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    // Set frequency scaling to 20% (reduces noise)
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    Serial.begin(9600);
}

void loop()
{
    // Read Red component
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    redFrequency = pulseIn(sensorOut, LOW);

    // Read Green component
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    greenFrequency = pulseIn(sensorOut, LOW);

    // Read Blue component
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blueFrequency = pulseIn(sensorOut, LOW);

    // Print RGB values as frequency
    Serial.print("Red: ");
    Serial.print(mapFrequencyToRGB(redFrequency));
    Serial.print("  Green: ");
    Serial.print(mapFrequencyToRGB(greenFrequency));
    Serial.print("  Blue: ");
    Serial.println(mapFrequencyToRGB(blueFrequency));

    delay(500);
}