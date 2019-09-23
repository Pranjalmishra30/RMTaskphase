int led=9;
int i;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  
  for(i=0;i<=255;i++)
  {
    analogWrite(led,i);
    delay(6);
  }
  for(;i>=0;i--)
  {
    analogWrite(led,i);
    delay(4);
  }
}    
  }
