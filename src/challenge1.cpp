// #include <Arduino.h>
// #include <vector>
// #include <math.h>
// #include <Servo.h>

// // Define L298N motor control pins
// #define enablePin1 9
// #define enablePin2 3
// #define motor1Pin1 10
// #define motor1Pin2 11
// #define motor2Pin1 12
// #define motor2Pin2 13

// int servoPin = 2;

// // Define color sensor pins
// #define S0 4
// #define S1 5
// #define S2 6
// #define S3 A2
// #define sensorOut A3

// // Define ultrasonic sensor pins
// #define trigPin A1
// #define echoPin A0

// // Calibration values for color sensor
// int redMin = 150;
// int redMax = 700;   // Red maximum value
// int greenMin = 170; // Green minimum value
// int greenMax = 800; // Green maximum value
// int blueMin = 150;  // Blue minimum value
// int blueMax = 700;  // Blue maximum value

// int redPW;
// int greenPW;
// int bluePW;

// int RPM = 255;

// int redValue, greenValue, blueValue;
// int distance_threshold = 20;

// Servo clawServo;

// int getRedPW()
// {
//     // Set sensor to read Red only
//     digitalWrite(S2, LOW);
//     digitalWrite(S3, LOW);
//     // Define integer to represent Pulse Width
//     int PW;
//     // Read the output Pulse Width
//     PW = pulseIn(sensorOut, LOW);
//     // Return the value
//     return PW;
// }

// // Function to read Green Pulse Widths
// int getGreenPW()
// {
//     // Set sensor to read Green only
//     digitalWrite(S2, HIGH);
//     digitalWrite(S3, HIGH);
//     // Define integer to represent Pulse Width
//     int PW;
//     // Read the output Pulse Width
//     PW = pulseIn(sensorOut, LOW);
//     // Return the value
//     return PW;
// }

// // Function to read Blue Pulse Widths
// int getBluePW()
// {
//     // Set sensor to read Blue only
//     digitalWrite(S2, LOW);
//     digitalWrite(S3, HIGH);
//     // Define integer to represent Pulse Width
//     int PW;
//     // Read the output Pulse Width
//     PW = pulseIn(sensorOut, LOW);
//     // Return the value
//     return PW;
// }

// String detectColor()
// {
//     // Read pulse width values for each color
//     redPW = getRedPW();
//     greenPW = getGreenPW();
//     bluePW = getBluePW();

//     // Check for black (high values across all channels)
//     if (redPW > 600 && greenPW > 600 && bluePW > 600)
//     {
//         return "BLACK";
//     }

//     if (redPW < greenPW && redPW < bluePW && redPW < 600)
//     {
//         return "RED";
//     }
//     else if (greenPW < redPW && greenPW < bluePW && greenPW < 600)
//     {
//         return "GREEN";
//     }
//     else if (bluePW < redPW && bluePW < greenPW && bluePW < 600)
//     {
//         return "BLUE";
//     }

//     return "UNKNOWN";
// }

// // Function for left turn
// int turnLeft(int time, int scale)
// {
//     // Stop first
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     // Right motor forward, left motor backward for left turn
//     digitalWrite(motor1Pin1, HIGH); // Right motor forward
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW); // Left motor backward
//     digitalWrite(motor2Pin2, HIGH);

//     // Set both motors to same speed for consistent turning
//     analogWrite(enablePin1, RPM);
//     analogWrite(enablePin2, RPM);

//     delay(time * scale);

//     // Stop after turn
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     return 1;
// }

// // Function for right turn
// int turnRight(int time, int scale)
// {
//     // Stop first
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     // Right motor backward, left motor forward for right turn
//     digitalWrite(motor1Pin1, LOW); // Right motor backward
//     digitalWrite(motor1Pin2, HIGH);
//     digitalWrite(motor2Pin1, HIGH); // Left motor forward
//     digitalWrite(motor2Pin2, LOW);

//     // Set both motors to same speed for consistent turning
//     analogWrite(enablePin1, RPM);
//     analogWrite(enablePin2, RPM);

//     delay(time * scale);

//     // Stop after turn
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     return 1;
// }

// // Function to read pulse width from the color sensor
// int readColorPulseWidth(bool s2State, bool s3State)
// {
//     digitalWrite(S2, s2State);
//     digitalWrite(S3, s3State);
//     return pulseIn(sensorOut, LOW);
// }

// // Function to drive the robot forward
// void driveForward(int time)
// {
//     analogWrite(enablePin1, RPM);
//     analogWrite(enablePin2, RPM);

//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, HIGH);
//     digitalWrite(motor2Pin2, LOW);

//     delay(time);

//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     analogWrite(enablePin1, 0);
//     analogWrite(enablePin2, 0);
// }

// void driveBackward(int time)
// {

//     analogWrite(enablePin1, RPM);
//     analogWrite(enablePin2, RPM);

//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, HIGH);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, HIGH);
//     delay(time);
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);
// }

// float getTime(double length)
// {

//     double angularVelocity = ((RPM * 2 * M_PI) / 60);
//     double forwardVelocity = angularVelocity * 3.25; // in cm/s

//     return (length / forwardVelocity);
// }

// void setup()
// {
//     // Motor pins setup
//     pinMode(motor1Pin1, OUTPUT);
//     pinMode(motor1Pin2, OUTPUT);
//     pinMode(enablePin1, OUTPUT);
//     pinMode(motor2Pin1, OUTPUT);
//     pinMode(motor2Pin2, OUTPUT);
//     pinMode(enablePin2, OUTPUT);

//     // Color sensor pins setup
//     pinMode(S0, OUTPUT);
//     pinMode(S1, OUTPUT);
//     pinMode(S2, OUTPUT);
//     pinMode(S3, OUTPUT);
//     pinMode(sensorOut, INPUT);

//     digitalWrite(S0, HIGH);
//     digitalWrite(S1, LOW);

//     // Ultrasonic sensor setup
//     pinMode(trigPin, OUTPUT);
//     pinMode(echoPin, INPUT);

//     // Set motor power levels
//     analogWrite(enablePin1, 125);
//     analogWrite(enablePin2, 125);

//     Serial.begin(115200);

//     clawServo.write(0);
// }

// std::vector<String> array = {"BLACK", "BLACK"};
// String color;

// void loop()
// {
    
//     int n = array.size();

//     if (n == 7) {
//         clawServo.write(150);
//         return;
//     }

//     color = detectColor();
//     driveForward(150);
//     color = detectColor();
//     if (color == array[0] || color == array[n-2]) {
//         turnLeft();
//     } else if (color != array[n-1]) {
//         array.push_back(color);
// }

//     delay(100);
// }