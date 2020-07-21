int led=12;
int i;
void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);  
}

void loop() {
 for(i=0;i<=255;i=i+2)
  {
    analogWrite(led,i);
    delay(1);
  }
  for(;i>=0;i=i-2)
  {
    analogWrite(led,i);
    delay(1);
  }
}    
