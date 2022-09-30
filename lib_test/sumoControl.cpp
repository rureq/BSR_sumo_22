#include "sumoControl.h"
#include "motorControl.h"
    
Sumo::Sumo(Motor& mot1, Motor& mot2): M1(mot1), M2(mot2)
{
  
}

void Sumo::rotate(bool dir, int speed)
{
  if (dir == 1)
  {
    M1.run(speed, 1);
    M2.run(speed, 0);
  }
  if (dir == 0)
  {
    M1.run(speed, 0);
    M2.run(speed, 1);
  }
  
}

void Sumo::rotateDeg(bool dir, int deg)
{
   if (dir == 1)
  {
    M1.run(255, 1);
    M2.run(255, 0);
    delay(5*deg);
    this->stop();
  }
  if (dir == 0)
  {
    M1.run(255, 0);
    M2.run(255, 1);
    delay(5*deg);
    this->stop();
  }
}

void Sumo::stop()
{
    M1.stop();
    M2.stop();
}

void Sumo::drive(bool dir, int speed)
{
  if (dir == 0)
  {
    M1.run(speed, 1);
    M2.run(speed, 1);
  }
  if (dir == 1)
  {
    M1.run(speed, 0);
    M2.run(speed, 0);
  }
}

