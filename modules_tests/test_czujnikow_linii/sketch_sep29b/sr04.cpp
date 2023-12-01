#include "sr04.h"

Ultrasonic::Ultrasonic(int echo, int trig)
{
    ECHO_PIN = echo;
    TRIG_PIN = trig;
    int time = 0;
    int dist = 0;
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
}

int Ultrasonic::read()
{
    digitalWrite(TRIG_PIN, LOW);    
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH); 
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    digitalWrite(ECHO_PIN, HIGH); 
    time = pulseIn(ECHO_PIN, HIGH);
    dist = time / 58;
    return dist;
}