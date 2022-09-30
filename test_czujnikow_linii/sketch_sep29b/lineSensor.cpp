#include "lineSensor.h"

LineSensor::LineSensor(int pin)
{
  ANALOG_PIN = pin;
  measurement = 0;
  pinMode(pin,INPUT);
  
}

int LineSensor::senseLine()
{
  measurement = 0;
  mean_no = 0;
  for(int i = 0; i<no_of_measurements; ++i){
    if (analogRead(ANALOG_PIN) != 0 ||  analogRead(ANALOG_PIN) != 1023){
      measurement += analogRead(ANALOG_PIN); 
      mean_no++;
    }
  }
  measurement /= no_of_measurements;

  if (measurement <= 200)
    return 1;
  if (measurement > 200)
    return 0;
  
  return -1;
}

int LineSensor::read()
{
return analogRead(ANALOG_PIN);

}