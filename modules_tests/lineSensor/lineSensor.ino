class LineSensor{
  private:
  int ANALOG_PIN;
  int measurement;
  int no_of_measurements = 3;
  int mean_no = 0;

  public:
  LineSensor(int pin){
    ANALOG_PIN = pin;
    measurement = 0;
    
  }
  int senseLine(){
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
  
};
LineSensor s1(A0);

void setup() {
   Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println(s1.senseLine());
  
}