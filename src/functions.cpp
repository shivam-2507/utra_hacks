#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string getColorMath(int red, int blue, int green) {

    string finalColor = "none";

    double redDistance = hypot(red - 255, green, blue);
    double blueDistance = hypot(red, green, blue-255);
    double greenDistance = hypot(red, green - 255, blue);

    int smallest_dist = min(redDistance, blueDistance, greenDistance);

    if (smallest_dist == redDistance) {
        finalColor = "red";
    }
    if (smallest_dist == blueDistance) {
        finalColor = "blue";
    }
    if (smallest_dist == greenDistance) {
        finalColor = "green";
    }

    return finalColor;
}

int inProximity (int ultrasonic_measurement){
    if ((ultrasonic_measurement) < 0.1){
        return 1;
    }
    return 0;
}