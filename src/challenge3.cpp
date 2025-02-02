// #include <Wire.h>
// #include <Adafruit_TCS34725.h>

// // Motor control pins
// #define LEFT_MOTOR_FORWARD 5
// #define LEFT_MOTOR_BACKWARD 6
// #define RIGHT_MOTOR_FORWARD 9
// #define RIGHT_MOTOR_BACKWARD 10
// // Ultrasonic sensor pins
// #define TRIG_PIN 11
// #define ECHO_PIN 12
// // LED pin
// #define LED_PIN 13

// // Color sensor setup
// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// // Color sequence: Red -> Green -> Blue -> Green -> Blue
// const char* colorSequence[] = {"Red", "Green", "Blue", "Green", "Blue"};
// int currentColorIndex = 0;

// // Store positions of visited tiles
// struct ColorPosition {
//     String color;
//     int visited;  // 0 = unvisited, 1 = visited
//     float x;
//     float y;
// };

// #define MAX_TILES 20
// ColorPosition visitedTiles[MAX_TILES];
// int tileCount = 0;

// // Navigation variables
// float currentX = 0;
// float currentY = 0;
// float currentAngle = 0;

// void setup() {
//     Serial.begin(9600);
    
//     pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
//     pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
//     pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
//     pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
//     pinMode(TRIG_PIN, OUTPUT);
//     pinMode(ECHO_PIN, INPUT);
//     pinMode(LED_PIN, OUTPUT);
    
//     if (!tcs.begin()) {
//         Serial.println("Color sensor not found!");
//         while (1);
//     }
// }

// void blinkLED() {
//     digitalWrite(LED_PIN, HIGH);
//     delay(200);
//     digitalWrite(LED_PIN, LOW);
//     delay(200);
// }

// void moveForward() {
//     analogWrite(LEFT_MOTOR_FORWARD, 150);
//     analogWrite(RIGHT_MOTOR_FORWARD, 150);
//     analogWrite(LEFT_MOTOR_BACKWARD, 0);
//     analogWrite(RIGHT_MOTOR_BACKWARD, 0);
    
//     // Update position (simplified)
//     currentX += cos(currentAngle) * 0.1;
//     currentY += sin(currentAngle) * 0.1;
// }

// void stopMotors() {
//     analogWrite(LEFT_MOTOR_FORWARD, 0);
//     analogWrite(RIGHT_MOTOR_FORWARD, 0);
//     analogWrite(LEFT_MOTOR_BACKWARD, 0);
//     analogWrite(RIGHT_MOTOR_BACKWARD, 0);
// }

// void turnRight() {
//     analogWrite(LEFT_MOTOR_FORWARD, 150);
//     analogWrite(RIGHT_MOTOR_FORWARD, 0);
//     analogWrite(LEFT_MOTOR_BACKWARD, 0);
//     analogWrite(RIGHT_MOTOR_BACKWARD, 150);
//     delay(500);
//     currentAngle += PI/2;
//     stopMotors();
// }

// void turnLeft() {
//     analogWrite(LEFT_MOTOR_FORWARD, 0);
//     analogWrite(RIGHT_MOTOR_FORWARD, 150);
//     analogWrite(LEFT_MOTOR_BACKWARD, 150);
//     analogWrite(RIGHT_MOTOR_BACKWARD, 0);
//     delay(500);
//     currentAngle -= PI/2;
//     stopMotors();
// }

// float getDistance() {
//     digitalWrite(TRIG_PIN, LOW);
//     delayMicroseconds(2);
//     digitalWrite(TRIG_PIN, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(TRIG_PIN, LOW);
//     long duration = pulseIn(ECHO_PIN, HIGH);
//     return duration * 0.034 / 2;  // Convert to cm
// }

// bool isNewTileLocation() {
//     for (int i = 0; i < tileCount; i++) {
//         float dx = visitedTiles[i].x - currentX;
//         float dy = visitedTiles[i].y - currentY;
//         if (sqrt(dx*dx + dy*dy) < 5) {  // Within 5cm of a known tile
//             return false;
//         }
//     }
//     return true;
// }

// void recordTileLocation(String color) {
//     if (tileCount < MAX_TILES && isNewTileLocation()) {
//         visitedTiles[tileCount].color = color;
//         visitedTiles[tileCount].visited = 1;
//         visitedTiles[tileCount].x = currentX;
//         visitedTiles[tileCount].y = currentY;
//         tileCount++;
//     }
// }

// String detectColor() {
//     uint16_t r, g, b, c;
//     tcs.getRawData(&r, &g, &b, &c);
    
//     // Normalize values
//     float sum = r + g + b;
//     float r_norm = r / sum;
//     float g_norm = g / sum;
//     float b_norm = b / sum;
    
//     if (r_norm > 0.4) return "Red";
//     if (g_norm > 0.4) return "Green";
//     if (b_norm > 0.4) return "Blue";
//     return "Unknown";
// }

// bool isValidNextTile(String detectedColor) {
//     if (currentColorIndex < 2) return true;  // First two colors can be any matching tiles
    
//     // For repeated colors, ensure we're not using the same tile
//     for (int i = 0; i < tileCount; i++) {
//         if (visitedTiles[i].color == detectedColor && visitedTiles[i].visited == 1) {
//             float dx = visitedTiles[i].x - currentX;
//             float dy = visitedTiles[i].y - currentY;
//             if (sqrt(dx*dx + dy*dy) < 5) {  // Within 5cm of a previously visited tile
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void loop() {
//     float distance = getDistance();
    
//     if (distance < 15) {  // Increased detection distance for better obstacle avoidance
//         stopMotors();
//         delay(200);
        
//         // Check left and right distances to decide turn direction
//         turnRight();
//         float rightDistance = getDistance();
//         turnLeft();
//         turnLeft();
//         float leftDistance = getDistance();
        
//         if (rightDistance > leftDistance) {
//             turnRight();  // Return to original position and turn right
//             turnRight();
//         } else {
//             turnRight();  // Return to original position and turn left
//         }
//     } else {
//         moveForward();
//         String detectedColor = detectColor();
        
//         if (detectedColor == colorSequence[currentColorIndex] && isValidNextTile(detectedColor)) {
//             Serial.print("Detected valid ");
//             Serial.println(detectedColor);
            
//             blinkLED();
//             recordTileLocation(detectedColor);
//             currentColorIndex++;
            
//             if (currentColorIndex >= 5) {
//                 Serial.println("Color sequence completed!");
//                 stopMotors();
//                 while (true) {
//                     blinkLED();  // Victory blink
//                 }
//             }
//             delay(1000);  // Wait to prevent multiple detections
//         }
//     }
    
//     delay(50);  // Small delay for stability
// }
