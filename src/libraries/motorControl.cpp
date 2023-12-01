#include "motorControl.h"


Motor::Motor(int EN, int DIR_1, int DIR_2)
{
    EN_PIN = EN;
    DIR_PIN_1 = DIR_1;
    DIR_PIN_2 = DIR_2;
}

void Motor::run(int speed, bool dir)
{
    if(dir == 1){
        digitalWrite(DIR_PIN_1, HIGH);
        digitalWrite(DIR_PIN_2, LOW);
        analogWrite(EN_PIN, speed);
    }
    else if (dir == 0){
        digitalWrite(DIR_PIN_1, LOW);
        digitalWrite(DIR_PIN_2, HIGH);
        analogWrite(EN_PIN, speed);
    }
    else{

    }
}

void Motor::stop(){
    analogWrite(EN_PIN, 0);
}
