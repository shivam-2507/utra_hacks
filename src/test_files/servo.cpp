// #include <Arduino.h>

// // Define L298N motor control pins
// #define enablePin1 9
// #define enablePin2 3
// #define motor1Pin1 10 // IN1 for motor 1 --> right (looking from the back)
// #define motor1Pin2 11 // IN2 for motor 1
// #define motor2Pin1 12 // IN3 for motor 2 --> left (looking from the back)
// #define motor2Pin2 13 // IN4 for motor 2

// void setup()
// {
//     // Set L298N motor control pins as output
//     pinMode(motor1Pin1, OUTPUT);
//     pinMode(motor1Pin2, OUTPUT);
//     pinMode(enablePin1, OUTPUT);

//     pinMode(motor2Pin1, OUTPUT);
//     pinMode(motor2Pin2, OUTPUT);
//     pinMode(enablePin2, OUTPUT);

//     analogWrite(enablePin1, 255); // power to the motor
//     analogWrite(enablePin2, 255);
//     // Start by driving the car forward
// }

// void loop()
// {
//     // Nothing to do in the loop, the car is already driving forward
//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);

//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, HIGH);

//     // Motor 2 moves forward
// }