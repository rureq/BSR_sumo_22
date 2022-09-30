#ifndef SUMOCONTROL_H
#define SUMOCONTROL_H

#include <Arduino.h>
#include "motorControl.h"


class Sumo
{
    Motor M1;
    Motor M2;
  
public:
    Sumo(Motor& mot1, Motor& mot2);
    void rotate(bool dir, int speed);
    void rotateDeg(bool dir, int deg);
    void drive(bool dir, int speed);
    void stop();

};

#endif