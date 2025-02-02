// #include <Arduino.h>

// #define enablePin1 9
// #define enablePin2 3
// #define motor1Pin1 10 // IN1 for motor 1 (right motor)
// #define motor1Pin2 11 // IN2 for motor 1
// #define motor2Pin1 12 // IN3 for motor 2 (left motor)
// #define motor2Pin2 13 // IN4 for motor 2


// // // Function for left turn
// void turnLeft(int time)
// {

//     Serial.println("In left turn function"); 
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
//     analogWrite(enablePin1, 255);
//     analogWrite(enablePin2, 255);

//     delay(time);

//     // Stop after turn
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);
// }



// // Function for right turn

// void turnRight(int time)
// {
//     Serial.println("In right turn function");
//     // Stop first
    
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     // Right motor forward, left motor backward for left turn
//     digitalWrite(motor1Pin1, LOW); // Right motor forward
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, HIGH); // Left motor backward
//     digitalWrite(motor2Pin2, LOW);

//     // Set both motors to same speed for consistent turning
//     analogWrite(enablePin1, 255);
//     analogWrite(enablePin2, 255);

//     delay(time);

//     // Stop after turn
//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

// }

// void turn180(){
//     turnLeft(750); 
//     delay(1000); 
//     turnLeft(750);
//     delay(1000); 
// }


// void driveStraight(int time){

//     digitalWrite(motor1Pin1, LOW);
//     digitalWrite(motor1Pin2, LOW);

//     digitalWrite(motor2Pin1, LOW);
//     digitalWrite(motor2Pin2, LOW);

//     analogWrite(enablePin1, (125));
//     analogWrite(enablePin2, (125));

//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);

//     digitalWrite(motor2Pin1, HIGH);
//     digitalWrite(motor2Pin2, LOW);

//     delay(time);
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
//     // Color sensor pins setup

//     // Set motor power levels


//     Serial.begin(9600);
// }

// void loop()
// {   

//     driveStraight(1000); 
//     delay(2000); 
//     turnRight(1000);
//     delay(2000); 
//     driveStraight(1000);
//     delay(2000);
//     turnLeft(1000);

// }