# UTRA Hacks Autonomous Path-Finding Robot

Created with **Arduino Uno R4 Minima**, **PlatformIO**, and **C++**.

The robot autonomously navigates a maze using only **color** and **ultrasonic sensors**, without human input. The project involved mechanical design, circuit wiring, and algorithm development for sensor-based navigation and obstacle avoidance.

## Features
- 3D printed claw to secure the flag in the middle of the maze
- Dynamic array used for efficient sensor data processing and decision-making
- Color-based navigation using the TCS230 color sensor
- Ultrasonic sensor for obstacle detection and avoidance
- Smooth motor control using the L298N motor driver

## Programs
**1. Color Detection Program**
- Reads pulse widths from the **TCS230 color sensor**.
- Detects colors (Red, Blue, Green) to guide navigation decisions.

**2. Obstacle Avoidance Program**
- Uses the **HC-SR04 ultrasonic sensor** to maintain a safe distance from obstacles.
- Stops and maneuvers when proximity falls below the threshold.

**3. Navigation Algorithm**
- Combines color detection and obstacle avoidance.
- Implements decision-making for pathfinding within the maze.
- Smooth motor control for driving and turning.

## Hardware Requirements
- **L298N Motor Driver**
- **2 x 12 Volt DC Brushless Motors**
- **TCS230 Color Sensor**
- **HC-SR04 Ultrasonic Sensor**
- **Arduino Uno R4 Minima**
- **Micro Servo**
- **Breadboard**
- **Jumper Wires**

## Software Requirements
- **PlatformIO IDE**

## Developed by
- **Kartik B.**
- **Nihar S.**
- **Tanmay S.**
- **Shivam W.**
- **Saswath Y.**

