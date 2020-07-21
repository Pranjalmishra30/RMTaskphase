int arr[8]={3,4,5,6,7,8,9,10};
int i,c=0,sum=0;
void setup() {
Serial.begin(9600);
for(i=0;i<8;i++)
  { 
   pinMode(arr[i],INPUT);
  } 
 
}

void loop() 
{
  for(i=0;i<8;i++)
   {
    if(digitalRead(arr[i])==LOW)  //white surface
     {
      digitalWrite(arr[i],LOW);
      Serial.print("B\t"); 
      delay(100);
     }
    
     else                        //white surface
     {
      digitalWrite(arr[i],HIGH);
      Serial.print("W\t");
      delay(100);
     }   
     Serial.println(); 
   }
}
