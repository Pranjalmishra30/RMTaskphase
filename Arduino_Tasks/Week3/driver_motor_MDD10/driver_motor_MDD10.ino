 char ch;
 int pwm_1=5;
 int pwm_2=6; 
 int dir_1=7;
 int dir_2=8; 
 int pwm_3=9;
 int pwm_4=10; 
 int dir_3=11;
 int dir_4=12;


 void setup()
 {
  Serial.begin(9600);
  pinMode(pwm_1,OUTPUT);
  pinMode(pwm_2,OUTPUT);
  pinMode(dir_1,OUTPUT);
  pinMode(dir_2,OUTPUT);
  pinMode(pwm_3,OUTPUT);
  pinMode(pwm_4,OUTPUT);
  pinMode(dir_3,OUTPUT);
  pinMode(dir_4,OUTPUT);
 }
 
 void loop()
 {
  while(Serial.available())
 { 
  ch=(char)Serial.read();
  
  if(ch=='f')
  {
   Serial.println("forward");
   digitalWrite(dir_1,HIGH);
   digitalWrite(dir_2,HIGH);
   digitalWrite(dir_3,HIGH);
   digitalWrite(dir_4,HIGH);
   analogWrite(pwm_1,255);
   analogWrite(pwm_2,255);
   analogWrite(pwm_3,255);
   analogWrite(pwm_4,255);
   }
   
  else if(ch=='b')
  {
   Serial.println("backward");
   digitalWrite(dir_1,LOW);
   digitalWrite(dir_2,LOW);
   digitalWrite(dir_3,LOW);
   digitalWrite(dir_4,LOW);
   analogWrite(pwm_1,255);
   analogWrite(pwm_2,255);
   analogWrite(pwm_3,255);
   analogWrite(pwm_4,255);
  }
  
  else if(ch=='r')
  {
    Serial.println("right");
    analogWrite(pwm_1,255);
    analogWrite(pwm_2,(255/2));
    analogWrite(pwm_3,255);
    analogWrite(pwm_4,(255/2));
  }
  
  else if(ch=='l')
  {
    Serial.println("left");
    analogWrite(pwm_1,(255/2));
    analogWrite(pwm_2, 255);
    analogWrite(pwm_3,(255/2));
    analogWrite(pwm_4, 255);     
  }

   else if(ch=='s')
  {
   Serial.println("stop");
   digitalWrite(dir_1,LOW);
   digitalWrite(dir_2,LOW);
   digitalWrite(dir_3,LOW);
   digitalWrite(dir_4,LOW);
   analogWrite(pwm_1,0);
   analogWrite(pwm_2,0);
   analogWrite(pwm_3,0);
   analogWrite(pwm_4,0);
   }

delay(100);
  
}

  
}
