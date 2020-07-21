int led=13;
int val=0;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
val=analogRead(A0);
Serial.println(val);
if(val>=200)
  digitalWrite(led,LOW);
else
   digitalWrite(led,HIGH);  


}
