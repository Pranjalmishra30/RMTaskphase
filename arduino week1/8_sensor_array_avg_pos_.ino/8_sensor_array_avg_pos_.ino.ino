int arr[8]={3,4,5,6,7,8,9,10};
int line_arr[8]={10,20,30,40,50,60,70,80};
int i,c,sum;
void setup() {
Serial.begin(9600);
for(i=0;i<8;i++)
  { 
   pinMode(arr[i],INPUT);
  } 
 
}

void loop() 
{
  sum=0;
  c=0;
  for(i=0;i<8;i++)
   {
    if(digitalRead(arr[i])==LOW)  //Black surface
     {
      sum+=line_arr[i];
      c++;
     }
   }
     
     
     if(c==0)
     {
      Serial.print("0");
     }
     else
     {
      Serial.print("line pos-");
      sum=sum/c;
      Serial.println(sum);
      delay(200);
     }
     
 }
