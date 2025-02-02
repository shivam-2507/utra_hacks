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

// // // Define ultrasonic sensor pins
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
//     digitalWrite(S2, LOW);
//     digitalWrite(S3, LOW);
//     int PW;
//     PW = pulseIn(sensorOut, LOW);
//     return PW;
// }

// int getGreenPW()
// {
//     digitalWrite(S2, HIGH);
//     digitalWrite(S3, HIGH);
//     int PW;
//     PW = pulseIn(sensorOut, LOW);
//     return PW;
// }

// int getBluePW()
// {
//     digitalWrite(S2, LOW);
//     digitalWrite(S3, HIGH);
//     int PW;
//     PW = pulseIn(sensorOut, LOW);
//     return PW;
// }

// String detectColor()
// {
//     redPW = getRedPW();
//     greenPW = getGreenPW();
//     bluePW = getBluePW();

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

// int turnLeft(int time, int scale)
// {
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, HIGH);

//     analogWrite(enablePin1, RPM);
//     analogWrite(enablePin2, RPM);

//     delay(time * scale);

//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     return 1;
// }

// int turnRight(int time, int scale)
// {
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, HIGH);
//     digitalWrite(motor2Pin1, HIGH);
//     digitalWrite(motor2Pin2, LOW);

//     analogWrite(enablePin1, RPM);
//     analogWrite(enablePin2, RPM);

//     delay(time * scale);

//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     return 1;
// }

// int readColorPulseWidth(bool s2State, bool s3State)
// {
//     digitalWrite(S2, s2State);
//     digitalWrite(S3, s3State);
//     return pulseIn(sensorOut, LOW);
// }

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
//     double forwardVelocity = angularVelocity * 3.25;

//     return (length / forwardVelocity);
// }

// String firstColor = "BLACK";
// String secondColor;
// String thirdColor;
// String fourthColor;

// void setup()
// {
//     pinMode(motor1Pin1, OUTPUT);
//     pinMode(motor1Pin2, OUTPUT);
//     pinMode(enablePin1, OUTPUT);
//     pinMode(motor2Pin1, OUTPUT);
//     pinMode(motor2Pin2, OUTPUT);
//     pinMode(enablePin2, OUTPUT);

//     pinMode(S0, OUTPUT);
//     pinMode(S1, OUTPUT);
//     pinMode(S2, OUTPUT);
//     pinMode(S3, OUTPUT);
//     pinMode(sensorOut, INPUT);

//     digitalWrite(S0, HIGH);
//     digitalWrite(S1, LOW);

//     pinMode(trigPin, OUTPUT);
//     pinMode(echoPin, INPUT);

//     analogWrite(enablePin1, 125);
//     analogWrite(enablePin2, 125);

//     Serial.begin(115200);

//     clawServo.write(0);
// }

// String color;

// void loop()
// {
//     Serial.println(detectColor());

//     while (color == "BLACK")
//     {
//         driveForward(150);
//         color = detectColor();
//     }

//     turnLeft(750, 1);
//     firstColor = color;

//     while (color == firstColor)
//     {
//         driveForward(150);
//         color = detectColor();

//     }

//     turnRight(750, 1);
//     secondColor = color;

//     while (color == secondColor)
//     {
//         driveForward(150);
//         color = detectColor();
//     }

//     turnRight(750, 1);
//     thirdColor = color;

//     while (color == thirdColor) {
//         driveForward(150);
//         color = detectColor();
//     }

//     delay(100);
// }
