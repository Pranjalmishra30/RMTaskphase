int led=9;
int val;
void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(38400); //baud rate for bluetooth module
}

void loop()
{
  val=0;
  if(Serial.available()>0)
   val=Serial.read();

   if(val=='1')
   {
    digitalWrite(led,HIGH);
    Serial.println("LED is On");    
   }
   else
   {
    digitalWrite(led,LOW);
    Serial.println("LED is off");
   }
}
