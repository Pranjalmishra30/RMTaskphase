int trigpin=7;
int echopin=6;
long duration;
long distance;

void setup() {
 Serial.begin(9600);
 pinMode(echopin,INPUT);
 pinMode(trigpin,OUTPUT);

}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW); 
  duration=pulseIn(echopin,HIGH);
  distance=(duration/2)*0.034;  //distance will be in cm
  Serial.println(distance);
  delay(50);
   

}
