
void setup() {
  Serial1.begin(38400);
  Serial.begin(38400);

}

void loop() {
 while(Serial1.available())    //getting info
 {
  Serial.print((char)Serial1.read());
 }
 while(Serial.available())     //sending info
 {
  Serial1.write(Serial.read());
 }
}
