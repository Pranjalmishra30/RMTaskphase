#Not tested
#include<Stepper.h>
const int stepsperrev=32; //change this for your motor; stepperrev=360/stepangle
Stepper my_stepper(stepsperrev,8,9,10,11); 

void setup()
{
  my_stepper.setSpeed(5);//in roations per minute
  Serial.begin(9600);
}

void loop()
{
  Serial.println("clockwise");
  my_stepper.step(stepsperrev);
  delay(500);
  Serial.println("Anti-clockwise");
  my_stepper.step(-stepsperrev);
  delay(500);
}
