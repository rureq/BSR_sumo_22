#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <Arduino.h>

class LineSensor
{
  int ANALOG_PIN;
  int measurement;
  int no_of_measurements = 3;
  int mean_no = 0;

public:
  LineSensor(int pin);
  int senseLine();
  int read();

};

#endif