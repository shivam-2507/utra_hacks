// #include <Arduino.h>

// #define enablePin1 9
// #define enablePin2 3
// #define motor1Pin1 10 // IN1 for motor 1 (right motor)
// #define motor1Pin2 11 // IN2 for motor 1
// #define motor2Pin1 12 // IN3 for motor 2 (left motor)
// #define motor2Pin2 13 // IN4 for motor 2

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
//     // Color sensor pins setup

//     // Set motor power levels
//     analogWrite(enablePin1, (125 * 1.05));
//     analogWrite(enablePin2, (125));

//     Serial.begin(9600);
// }

// void loop()
// {
//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);

//     digitalWrite(motor2Pin1, HIGH);
//     digitalWrite(motor2Pin2, LOW);
// }