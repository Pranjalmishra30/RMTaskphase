
#include <Servo.h>
int pos;
Servo servo_9;

void setup()
{
  Serial.begin(9600);
  servo_9.attach(9);
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 1)
  {
        servo_9.write(pos);
        delay(15); 
  }
  
  for (pos = 180; pos >= 0; pos -= 1) 
  {
    servo_9.write(pos);
    delay(15); 
  }
}

/*
  servo_9.write(0);  // tell servo to go to a particular angle
  delay(1000);
  
  servo_9.write(90);              
  delay(1000); 
  
  servo_9.write(135);              
  delay(1000);
  
  servo_9.write(180);              
  delay(1000);                     
*/
