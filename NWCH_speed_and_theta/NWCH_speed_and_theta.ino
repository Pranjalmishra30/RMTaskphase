
# define DEG2RAD(x) x * 0.0174533

class NWCH_bot
{
  int *angles;
  bool *reverseDIRs;
  int *PWM_pins;    // List of PWM pins
  int *DIR_pins;   // List of DIR pins
  float v[4];
  public:
  void PWM_move_bot(int,float,float);
  void bot_move(int,float,float);
  void Attachpins (int*,int*,bool*);
  void initializewheels (int *);
 
};

void NWCH_bot::Attachpins(int *PWM_PINs, int *DIR_PINs , bool*reverseDIRS)
{
    this->reverseDIRs = reverseDIRS;
    // Attach PWM and DIR pins to the motor drivers
    this->PWM_pins = PWM_PINs;
    this->DIR_pins = DIR_PINs;
    for (int i = 0; i <4; i++) {
        // PWM and DIR pins are OUTPUT type
        pinMode(this->PWM_pins[i], OUTPUT);
        pinMode(this->DIR_pins[i], OUTPUT);
    }
}

void NWCH_bot::initializewheels (int *angles_deg)
{
  this->angles=angles_deg;
  
}

void NWCH_bot:: PWM_move_bot(int PWM , float angle , float w)
{
 angle=DEG2RAD(angle);
 float Vx=PWM*sin(angle);
 float Vy=PWM*cos(angle);
 for(int i=0;i<4;i++)
 {
  float vect= Vx*sin(this->angles[i]) + Vy*cos(this->angles[i]) +w;
  this->v[i]=int(vect);
}
}

void NWCH_bot::bot_move(int PWM , float angle , float w)
{
  PWM_move_bot(PWM,angle,w);
   for(int i=0;i<4;i++)
  {
   if((this->v[i])<0)
   {
   digitalWrite(this->DIR_pins[i],LOW);
   this->v[i]=(-1)*(this->v[i]);
   if(this->reverseDIRs)
   digitalWrite(this->DIR_pins[i],HIGH);
   }
   else
   {
    digitalWrite(this->DIR_pins[i],HIGH);
   if(this->reverseDIRs)
   digitalWrite(this->DIR_pins[i],LOW);
    
   }
  }
  for(int i=0;i<4;i++)
   analogWrite(this->PWM_pins[i],this->v[i]);
  
}
 

NWCH_bot B;

int PWM[]={7,8,9,10};
int DIR[]={50,51,52,52};
int angles[]={45,135,315,225};
bool reverse[]={true,false,false,true};
int s;
float theta,w;

void setup()
{
  Serial.begin(115200);
  B.Attachpins(PWM,DIR,reverse);
  B.initializewheels(angles);
}
void loop()
{
  
  char gutter;
if(Serial.available()){
      Serial.print("Serial available : ");
      Serial.print(Serial.available());
      Serial.print(",");
      s = Serial.parseInt();
      theta = Serial.parseInt();
      w = Serial.parseInt();
      Serial.print(s);
      Serial.print(",");
      Serial.print(theta);
      Serial.print(",");
      Serial.println(w);
      B.bot_move(s,theta,w);
      while(Serial.available())
      {
        gutter=Serial.read();
      }
   }
   
   


  
  
}


  
