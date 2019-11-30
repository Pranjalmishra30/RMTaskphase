/*class LSA_bot
{
  float angles;
  int reverseDIRs[4];
  int PWM_pins[4];    // List of PWM pins
  int DIR_pins[4];   // List of DIR pins
  float pseudo_matrix[4][3]= {
     -0.3536,-0.3536,0.2500
     -0.3536,0.3536,0.2500
     0.3536,-0.3536,0.2500
     0.3536,0.3536,0.2500
    }
  float v[4];
  void velocity(float*getvel);
  void move_bot();
  void Attachpins (int *PWM_PINs,int*DIR_PINs);

}*/





int analogpin1=0; //connect AN of LSA08 to analog pin 0 of arduino
int analogpin2=1; //connect AN of LSA08 to analog pin 0 of arduino
int PWM_pins[]={7,8,9,10};
int DIR_pins[]={50,51,52,53};

bool reverseDIRs[]={true,false,true,false};
int readval,positionVal,readval2,positionVal2;
int junction;

void setup() {

  Serial.begin(115200);
 for(int i=0;i<4;i++)
 {
  pinMode(PWM_pins[i],OUTPUT);
  pinMode(DIR_pins[i],OUTPUT);
 }
 //initial conditions
 for(int i=0;i<4;i++)
 {
  digitalWrite(PWM_pins[i],LOW);
  digitalWrite(DIR_pins[i],LOW);
 }


}

void loop() {
  readval=analogRead(analogpin);
  positionVal=((float)readval/921)*70;
  //The ADC modules of Arduino Uno support 10-bit conversion, so each step size of the result represent 5V/2^10= 4.88mV,
  //meaning that an increase of 4.88mV in the reading will increase the result of ADC conversion by 1.
  //So, to convert the voltage signal back into what we human can understand,
  //we need to use the formula ((ADC result)/921)*70 in order to get the actual position of the line.
  //Why divide by 921? Because 921 is the digital representation for 4.5V in 10-bit ADC.
  readval2=analogRead(analogpin2);
  positionVal2=((float)readval2/921)*70;

  if(positionVal2)
  junction++;
  
  // Line at left when 0 - 18, move left
  if(positionVal <= 18)
  moveLeft();

  // Line at middle when 19 - 52, move forward
  else if(positionVal <= 52)
  moveForward();

  // Line at right when 53 - 70, move right
  else if(positionVal <= 70)
  moveRight();

  // If no line is detected, stay at the position
  else
  wait();

  delay(1000);
  
}
void moveLeft() {
  // For robot to move left, right motor has to be faster than left motor
  analogWrite(PWM_pins[0],80);
  analogWrite(PWM_pins[2],80);
  analogWrite(PWM_pins[1],200);
  analogWrite(PWM_pins[3],200);
}

void moveRight() {
  // For robot to move right, left motor has to be faster than right motor
  analogWrite(PWM_pins[1],80);
  analogWrite(PWM_pins[3],80);
  analogWrite(PWM_pins[0],200);
  analogWrite(PWM_pins[2],200);
}

void moveForward() {
  // For robot to move forward, both motors have to be same speed
  analogWrite(PWM_pins[0],200);
  analogWrite(PWM_pins[1],200);
  analogWrite(PWM_pins[2],200);
  analogWrite(PWM_pins[3],200);
}

void wait() {
  // Function to makes the robot stay
  analogWrite(PWM_pins[0],0);
  analogWrite(PWM_pins[1],0);
  analogWrite(PWM_pins[2],0);
  analogWrite(PWM_pins[3],0);
}
