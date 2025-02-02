// #include <Arduino.h>

// // Define TCS3200 pins
// #define S0 4
// #define S1 5
// #define S2 6
// #define S3 A2
// #define sensorOut A3

// // Variables for color pulse width measurements
// int redPW;
// int greenPW;
// int bluePW;

// void setup()
// {
//     // Setup sensor pins
//     pinMode(S0, OUTPUT);
//     pinMode(S1, OUTPUT);
//     pinMode(S3, OUTPUT);
//     pinMode(S2, OUTPUT);
//     pinMode(sensorOut, INPUT);

//     // Set frequency scaling to 20%
//     digitalWrite(S0, HIGH);
//     digitalWrite(S1, LOW);

//     // Start serial monitor
//     Serial.begin(9600);
// }

// // Function to read Red Pulse Width
// int getRedPW()
// {
//     digitalWrite(S2, LOW);
//     digitalWrite(S3, LOW);
//     return pulseIn(sensorOut, LOW);
// }

// // Function to read Green Pulse Width
// int getGreenPW()
// {
//     digitalWrite(S2, HIGH);
//     digitalWrite(S3, HIGH);
//     return pulseIn(sensorOut, LOW);
// }

// // Function to read Blue Pulse Width
// int getBluePW()
// {
//     digitalWrite(S2, LOW);
//     digitalWrite(S3, HIGH);
//     return pulseIn(sensorOut, LOW);
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

//     // Find the dominant color
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

// void loop()
// {
//     String color = detectColor();

//     // Print the values and detected color
//     Serial.print("Red PW = ");
//     Serial.print(redPW);
//     Serial.print(" - Green PW = ");
//     Serial.print(greenPW);
//     Serial.print(" - Blue PW = ");
//     Serial.print(bluePW);
//     Serial.print(" - Detected Color: ");
//     Serial.println(color);

//     delay(500);
// }