#ifndef SR04_H
#define SR04_H

#include <Arduino.h>

class Ultrasonic{
    int TRIG_PIN;
    int ECHO_PIN;
    long time;
    int dist;

public:
    Ultrasonic(int echo, int trig);
    int read();

};

#endif