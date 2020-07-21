class LSA_bot
{
  
  int *reverseDIRs;
  int *PWM_pins;    // List of PWM pins
  int *DIR_pins;   // List of DIR pins
  float pseudo_matrix[4][3]= 
  {-0.3536,-0.3536,0.2500,
  -0.3536,0.3536,0.2500,
  0.3536,-0.3536,0.2500,
  0.3536,0.3536,0.2500 };
     
  float v[4];
  public:
  void velocity(float[][1]);
  void move_bot();
  void Attachpins (int *,int*,bool*);
};

void LSA_bot::Attachpins(int *PWM_PINs, int *DIR_PINs , bool*reverseDIRS)
{
    this->reverseDIRs = reverseDIRs;
    // Attach PWM and DIR pins to the motor drivers
    this->PWM_pins = PWM_PINs;
    this->DIR_pins = DIR_PINs;
    for (int i = 0; i <4; i++) {
        // PWM and DIR pins are OUTPUT type
        pinMode(this->PWM_pins[i], OUTPUT);
        pinMode(this->DIR_pins[i], OUTPUT);
    }
}

void LSA_bot::velocity(float getvel[][1])
{
  int i,j,k;
  for(i=0;i<4;i++)     //getting individual velocities
  {
    for(j=0;j<1;j++)
    {
      this->v[i]=0;
      for(k=0;k<3;k++)
      {
        this->v[i]+=(this->pseudo_matrix[i][k])*getvel[k][j];
      }
    }
  }
}

void LSA_bot:: move_bot() //For bot going straight
{
  for(int i=0;i<4;i++)
  {
   analogWrite(this->PWM_pins[i],this->v[i]);
  }
}

LSA_bot B;

int PWM[]={7,8,9,10};
int DIR[]={50,51,52,53};
bool reverse[]={"True","False","True","False"};
float x,y,w;
float vel[3][1];
void setup()
{
  Serial.begin(115200);
  B.Attachpins(PWM,DIR,reverse);
}

void loop()
{
  while(Serial.available())
  {
    Serial.println("enter x,y,w");
    x=Serial.read();
    y=Serial.read();
    w=Serial.read();
    vel[0][0]=x;
    vel[1][0]=y;
    vel[2][0]=w;

   B.velocity(vel);
   B.move_bot();
   delay(1000);
  }
}


  
