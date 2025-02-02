// #include <Arduino.h>
// #include <Servo.h>

// // Define L298N motor control pins
// #define enablePin1 9
// #define enablePin2 3
// #define motor1Pin1 10 // IN1 for motor 1 (right motor)
// #define motor1Pin2 2  // IN2 for motor 1
// #define motor2Pin1 12 // IN3 for motor 2 (left motor)
// #define motor2Pin2 13 // IN4 for motor 2

// // Define color sensor pins
// #define S0 4
// #define S1 5
// #define S2 6
// #define S3 7
// #define sensorOut 8

// // Define ultrasonic sensor pins
// #define trigPin A5
// #define echoPin A4

// // Calibration values for color sensor
// int redMin = 20, redMax = 600;
// int greenMin = 30, greenMax = 600;
// int blueMin = 25, blueMax = 550;

// int redValue, greenValue, blueValue;

// Servo clawServo;
// int clawPin = 11;

// int turnRobot(int angle)
// {
//     if (angle == 90)
//     {
//         // Stop the robot briefly before turning
//         digitalWrite(motor1Pin1, LOW);
//         digitalWrite(motor1Pin2, LOW);
//         digitalWrite(motor2Pin1, LOW);
//         digitalWrite(motor2Pin2, LOW);

//         // Set both wheels to move but at different speeds for a smooth turn
//         digitalWrite(motor1Pin1, HIGH); // Right motor forward
//         digitalWrite(motor1Pin2, LOW);
//         digitalWrite(motor2Pin1, LOW); // Left motor forward
//         digitalWrite(motor2Pin2, HIGH);

//         // Differential speed for turning
//         analogWrite(enablePin1, 255); // Full speed for the right motor
//         analogWrite(enablePin2, 150); // Reduced speed for the left motor

//         // Adjust the delay based on your robot's turning speed and wheelbase
//         delay(1000); // Fine-tune this value for a precise 90-degree turn

//         // Stop the robot after the turn
//         digitalWrite(motor1Pin1, LOW);
//         digitalWrite(motor1Pin2, LOW);
//         digitalWrite(motor2Pin1, LOW);
//         digitalWrite(motor2Pin2, LOW);

//         return 1; // Success
//     }
//     return 0; // Invalid angle
// }

// // Function to read pulse width from the color sensor
// int readColorPulseWidth(bool s2State, bool s3State)
// {
//     digitalWrite(S2, s2State);
//     digitalWrite(S3, s3State);
//     return pulseIn(sensorOut, LOW);
// }

// // Function to drive the robot forward
// void driveForward()
// {
//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, HIGH);
//     digitalWrite(motor2Pin2, LOW);
// }

// // Function to read distance from ultrasonic sensor
// long readDistance()
// {
//     digitalWrite(trigPin, LOW);
//     delayMicroseconds(2);
//     digitalWrite(trigPin, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(trigPin, LOW);

//     long duration = pulseIn(echoPin, HIGH);
//     long distance = (duration * 0.034) / 2;
//     return distance;
// }

// void setClaw(double angle)
// {
//     // Set the claw to the desired angle
//     clawServo.write(angle);
// }

// void closeClaw()
// { // Close the claw
//     setClaw(70);
// }

// void openClaw()
// {
//     setClaw(20);
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
//     analogWrite(enablePin1, 255);
//     analogWrite(enablePin2, 255);

//     clawServo.attach(clawPin);
//     Serial.begin(9600);
// }

// void loop()
// {

//     // Drive the robot forward
//     turnRobot(90);

//     // // Read color sensor values
//     redValue = map(readColorPulseWidth(LOW, LOW), redMin, redMax, 255, 0);
//     greenValue = map(readColorPulseWidth(HIGH, HIGH), greenMin, greenMax, 255, 0);
//     blueValue = map(readColorPulseWidth(LOW, HIGH), blueMin, blueMax, 255, 0);

//     // // Print color sensor values
//     // Serial.print("R: ");
//     Serial.print(redValue);
//     Serial.print(" ");
//     Serial.print(greenValue);
//     Serial.print(" ");
//     Serial.println(blueValue);

//     // // Read and print ultrasonic sensor distance
//     long distance = readDistance();
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.println(" cm");

//     delay(500);
// }
