char ch;
int PWM_pins[]={7,8,9,10};
int DIR_pins[]={50,51,52,53}; 

 void setup()
 {
  Serial.begin(9600);
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
 
 void loop()
 {
  while(Serial.available())
 { 
  ch=(char)Serial.read();
  
  if(ch=='f')
  {
   Serial.println("forward");
   for(int i=0;i<4;i++)
   {
   digitalWrite(DIR_pins[i],HIGH);
   analogWrite(PWM_pins[i],200);
   }
  } 
   
  else if(ch=='b')
  {
   Serial.println("backward");
   for(int i=0;i<4;i++)
   {
   digitalWrite(DIR_pins[i],LOW);
   analogWrite(PWM_pins[i],200);
   }
  }
  
  else if(ch=='r')
  {
    Serial.println("right");
  analogWrite(PWM_pins[1],80);
  analogWrite(PWM_pins[3],80);
  analogWrite(PWM_pins[0],200);
  analogWrite(PWM_pins[2],200);
  }
  
  else if(ch=='l')
  {
    Serial.println("left");
  analogWrite(PWM_pins[0],80);
  analogWrite(PWM_pins[2],80);
  analogWrite(PWM_pins[1],200);
  analogWrite(PWM_pins[3],200);    
  }

   else if(ch=='s')
  {
   Serial.println("stop");
   for(int i=0;i<4;i++)
   {
   digitalWrite(DIR_pins[i],LOW);
   analogWrite(PWM_pins[i],0);
   }
   }

delay(100);
  
}

  
}
