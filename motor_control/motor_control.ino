class Motor{
  private:
  int EN_PIN;
  int DIR_PIN_1;
  int DIR_PIN_2;
  
  public:
  Motor(int EN, int DIR_1, int DIR_2){
    EN_PIN = EN;
    DIR_PIN_1 = DIR_1;
    DIR_PIN_2 = DIR_2;
  }
  void run(int speed, bool dir){
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
  void stop(){
    analogWrite(EN_PIN, 0);
  }
};

//zmienne globalne
//definicja pinów silników
Motor MotL(5,2,3);
Motor MotR(6,4,7);
//jakieś zmienne do testów
int speed = 0;
int lop = 0;
double diam = 68.0;
double dist = 208.0;
double RPS = 1.875;
double spit = RPS*diam*3.1415;
double circle_dist = 3.1415*dist;
int time_on = 1000*(circle_dist/spit)*1.61;


void setup() {


}

void loop() {

  MotL.run(255,1);
  MotR.run(255,0);
  delay(time_on);
  MotL.stop();
  MotR.stop();

  delay(1000);

}
