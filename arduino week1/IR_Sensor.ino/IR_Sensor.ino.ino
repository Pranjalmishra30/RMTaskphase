int ir_pin=10;
void setup() {
Serial.begin(9600);
pinMode(ir_pin,INPUT);

}

void loop() {
  
  if(digitalRead(ir_pin)==HIGH)
    {
      digitalWrite(LED_BUILTIN,HIGH);
      Serial.println("object detected");

    }
  else
    {
      digitalWrite(LED_BUILTIN,LOW);
      Serial.println("object not detected");
     
    }
     delay(500);
}
