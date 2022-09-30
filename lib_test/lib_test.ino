#include "lineSensor.h"
#include "motorControl.h"
#include "sr04.h"
#include "sumoControl.h"

//dołączenie hardware'u
LineSensor s1(A0); //sensor linii CNY70
LineSensor s2(A1);
LineSensor s3(A3);

Ultrasonic U1(8,9); //SR04 Echo,Trig
Motor M1(6,7,4); //kanał sterownika silników L298N
Motor M2(5,3,2);

int distance = 4000;
int new_distance = 4000;
Sumo sumo(M1,M2);
//int wynik = 0;

int search()
{
  int distance = U1.read();
  while(U1.read()>=90)//było 40
  {
    Serial.println("Searching!");
    sumo.rotate(1,255);
    U1.read();
  }
  sumo.stop();
  return distance;
}

void chase(int distance)
{
  int new_distance = U1.read();
  int ldtc = linedetect();
  while(new_distance <= distance && linedetect() != 1)
  {
    sumo.drive(1,255);
    Serial.println("Chasing!");
    distance = new_distance;
    new_distance = U1.read();
    ldtc = linedetect();
  }
  if (ldtc == 1)
  {
    escape();
    return;
  }
  

}

void turnaround()
{
  sumo.rotateDeg(1,180);
}

int linedetect()
{
  int l1 = 0;
  int l2 = 0;
  int l3 = 0;
  int meas_no = 3;

  for(int i = 0; i < meas_no; ++i)
  { 
    l1 += s1.senseLine();
    l2 += s2.senseLine();
    l3 += s3.senseLine();
  }
  l1 /= meas_no;
  l2 /= meas_no;
  l3 /= meas_no;

  if(l1 >= 1 || l2 >= 1 || l3 >= 1)
  {
    Serial.println("Line detected!");
    return 1;
  }
  return 0;
}

void escape()
{
  Serial.println("Escaping!");
  sumo.stop();
  sumo.drive(0, 255);
  delay(500);
  turnaround();
  sumo.drive(1, 255);
  delay(500);
}

void setup() {
   Serial.begin(9600);
   delay(2000);
}


void loop() {
  distance = search();
  Serial.println(distance);
  chase(distance);  
  
  //Serial.println(s1.senseLine());
  // delay(2000);
  // sumo.drive(1, 255);
  // delay(2000);
  // sumo.drive(0,255);
  // delay(2000);
  // sumo.rotate(1, 255);
  // delay(2000);
  // sumo.rotate(0,255);
  // delay(2000);
  //M1.run(255,1);
  //M1.stop();
  //wynik = U1.read();
  //Serial.println(wynik);
  
}