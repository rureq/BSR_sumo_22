#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <Arduino.h>

class Motor
{
  int EN_PIN;
  int DIR_PIN_1;
  int DIR_PIN_2;
  
public:
  Motor(int EN, int DIR_1, int DIR_2);
  void run(int speed, bool dir);
  void stop();
};

#endif