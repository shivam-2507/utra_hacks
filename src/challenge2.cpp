//
// CHALLENGE 2
//

#include <Arduino.h>

// Define L298N motor control pins
#define enablePin1 9
#define enablePin2 3
#define motor1Pin1 10 // IN1 for motor 1 (right motor)
#define motor1Pin2 11 // IN2 for motor 1
#define motor2Pin1 12 // IN3 for motor 2 (left motor)
#define motor2Pin2 13 // IN4 for motor 2

// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 A2
#define sensorOut A3

// Define ultrasonic sensor pins
#define trigPin A1
#define echoPin A0

// Calibration values for color sensor
// int redMin = 150;   // Red minimum value
// int redMax = 700;   // Red maximum value
// int greenMin = 170; // Green minimum value
// int greenMax = 800; // Green maximum value
// int blueMin = 150;  // Blue minimum value
// int blueMax = 700;  // Blue maximum value

int redPW;
int greenPW;
int bluePW;

int redValue, greenValue, blueValue;
int distance_threshold = 20;
int getRedPW()
{
    // Set sensor to read Red only
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Define integer to represent Pulse Width
    int PW;
    // Read the output Pulse Width
    PW = pulseIn(sensorOut, LOW);
    // Return the value
    return PW;
}

// Function to read Green Pulse Widths
int getGreenPW()
{
    // Set sensor to read Green only
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    // Define integer to represent Pulse Width
    int PW;
    // Read the output Pulse Width
    PW = pulseIn(sensorOut, LOW);
    // Return the value
    return PW;
}

// Function to read Blue Pulse Widths
int getBluePW()
{
    // Set sensor to read Blue only
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    // Define integer to represent Pulse Width
    int PW;
    // Read the output Pulse Width
    PW = pulseIn(sensorOut, LOW);
    // Return the value
    return PW;
}

String detectColor()
{
    // Read pulse width values for each color
    redPW = getRedPW();
    greenPW = getGreenPW();
    bluePW = getBluePW();

    // Check for black (high values across all channels)
    if (redPW > 600 && greenPW > 600 && bluePW > 600)
    {
        return "BLACK";
    }

    if (redPW < greenPW && redPW < bluePW && redPW < 600)
    {
        return "RED";
    }
    else if (greenPW < redPW && greenPW < bluePW && greenPW < 600)
    {
        return "GREEN";
    }
    else if (bluePW < redPW && bluePW < greenPW && bluePW < 600)
    {
        return "BLUE";
    }

    return "UNKNOWN";
}

// // Function for left turn
void turnLeft(int time)
{

    Serial.println("In left turn function");
    // Stop first
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    // Right motor forward, left motor backward for left turn
    digitalWrite(motor1Pin1, HIGH); // Right motor forward
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW); // Left motor backward
    digitalWrite(motor2Pin2, HIGH);

    // Set both motors to same speed for consistent turning
    analogWrite(enablePin1, 255);
    analogWrite(enablePin2, 255);

    delay(time);

    // Stop after turn
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

// Function for right turn

void turnRight(int time)
{
    Serial.println("In right turn function");
    // Stop first

    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    // Right motor forward, left motor backward for left turn
    digitalWrite(motor1Pin1, LOW); // Right motor forward
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH); // Left motor backward
    digitalWrite(motor2Pin2, LOW);

    // Set both motors to same speed for consistent turning
    analogWrite(enablePin1, 255);
    analogWrite(enablePin2, 255);

    delay(time);

    // Stop after turn
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void turn180()
{
    turnLeft(750);
    delay(1000);
    turnLeft(750);
    delay(1000);
}

void driveStraight(int time)
{

    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    analogWrite(enablePin1, (125));
    analogWrite(enablePin2, (125));

    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);

    delay(time);
}

// Function to read pulse width from the color sensor
int readColorPulseWidth(bool s2State, bool s3State)
{
    digitalWrite(S2, s2State);
    digitalWrite(S3, s3State);
    return pulseIn(sensorOut, LOW);
}

// Function to drive the robot forward
void driveForward(int time)
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(time);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

// Function to read distance from ultrasonic sensor
long readDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.034) / 2;
    return distance;
}

void decisionMaker(String colour)
{
    if (colour == "RED")
    {
        Serial.print("RED TURNING");
        turn180();
    }
    else if (colour == "BLUE")
    {
        Serial.print("BLUE TURNING");
        turnLeft(750);
    }
    else if (colour == "GREEN")
    {
        Serial.print("GREEN TURNING");
        turnRight(750);
    }
}

void setup()
{
    // Motor pins setup
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enablePin1, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enablePin2, OUTPUT);

    // Color sensor pins setup
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);

    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    // Ultrasonic sensor setup
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Set motor power levels
    analogWrite(enablePin1, 125);
    analogWrite(enablePin2, 125);

    Serial.begin(9600);
}

void loop() // drive forward 750 ms, read distance, if in proximity, read color, print color
            //                                      else move forward
{
    long distance = readDistance();
    Serial.print(" Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < distance_threshold)
    {
        // redValue = map(readColorPulseWidth(LOW, LOW), redMin, redMax, 255, 0);
        // greenValue = map(readColorPulseWidth(HIGH, HIGH), greenMin, greenMax, 255, 0);
        // blueValue = map(readColorPulseWidth(LOW, HIGH), blueMin, blueMax, 255, 0);
        String color = detectColor();
        Serial.print(" Color: ");
        Serial.print(color);
        Serial.print("Red = ");
        Serial.print(redValue);
        Serial.print(" - Green = ");
        Serial.print(greenValue);
        Serial.print(" - Blue = ");
        Serial.println(blueValue);

        Serial.print(color);

        decisionMaker(color);
    }
    else
    {
        driveForward(750);
    }

    delay(100);
}