// // Define color sensor pins 720 1020 850 -- 100 125 110
// #include <Arduino.h>

// int S0 = 4;
// int S1 = 5;
// int S2 = 6;
// int S3 = A2;

// int sensorOut = A3;

// // Calibration Values
// // *Get these from Calibration Sketch
// int redMin = 150;   // Red minimum value
// int redMax = 700;   // Red maximum value
// int greenMin = 170; // Green minimum value
// int greenMax = 800; // Green maximum value
// int blueMin = 150;  // Blue minimum value
// int blueMax = 700;

// // Variables for Color Pulse Width Measurements
// int redPW = 0;
// int greenPW = 0;
// int bluePW = 0;

// // Variables for final Color values
// int redValue;
// int greenValue;
// int blueValue;

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

// void setup()
// {
//     // Set S0 - S3 as outputs
//     pinMode(S0, OUTPUT);
//     pinMode(S1, OUTPUT);
//     pinMode(S2, OUTPUT);
//     pinMode(S3, OUTPUT);

//     // Set Sensor output as input
//     pinMode(sensorOut, INPUT);

//     // Set Frequency scaling to 20%
//     digitalWrite(S0, HIGH);
//     digitalWrite(S1, LOW);

//     // Setup Serial Monitor
//     Serial.begin(9600);
// }

// void loop()
// {
//     // Read Red value
//     redPW = getRedPW();
//     // Map to value from 0-255
//     redValue = map(redPW, redMin, redMax, 255, 0);
//     // Delay to stabilize sensor
//     delay(200);

//     // Read Green value
//     greenPW = getGreenPW();
//     // Map to value from 0-255
//     greenValue = map(greenPW, greenMin, greenMax, 255, 0);
//     // Delay to stabilize sensor
//     delay(200);

//     // Read Blue value
//     bluePW = getBluePW();
//     // Map to value from 0-255
//     blueValue = map(bluePW, blueMin, blueMax, 255, 0);
//     // Delay to stabilize sensor
//     delay(200);

//     // Print output to Serial Monitor
//     Serial.print("Red = ");
//     Serial.print(redValue);
//     Serial.print(" - Green = ");
//     Serial.print(greenValue);
//     Serial.print(" - Blue = ");
//     Serial.println(blueValue);
// }
