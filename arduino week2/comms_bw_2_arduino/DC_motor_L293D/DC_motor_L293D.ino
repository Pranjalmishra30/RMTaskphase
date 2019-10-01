char ch;
int enable =8;
//motor 1
int in1=6; //7
int in2=7; //2

//motor 2
int in3=4; // 15
int in4=5; // 10

void setup()
{
  Serial.begin(9600);
  pinMode(enable,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  digitalWrite(enable,HIGH);
}

void loop()
{
  while(Serial.available())
{ 
  ch=(char)Serial.read();
  if(ch=='f')
  {
    Serial.println("forward");
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
  }
  
 else if(ch=='b')
  {
    Serial.println("backward");
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }
  
  else if(ch=='s')
  {
    Serial.println("stop");
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
  }

 } 
 /*
 digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   */
}
