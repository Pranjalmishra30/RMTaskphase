#include <iostream>
#include<math.h>
using namespace std;

void global_local(int x,int y,int z,int Tw[4][4])
{
    int i,j,k;
  int Pw[4][1],Pl[4][1];


  for(i=0;i<4;i++)
  {
    for(j=0;j<1;j++)
    { Pl[i][j]=0;
      for(k=0;k<4;k++)
      {
         Pl[i][j]+=Tw[i][k]*Pw[k][j];
      }
    }
  }

   cout<<"local coordinates :\n";
    cout<<"x = "<<Pl[0][0]<<" y = "<<Pl[1][0]<<" Z = "<<Pl[2][0]<<"\n";

}

void local_global(int a,int b,int c,float theta)
{
  float Pa[4][1],Ta[4][4],Ph[4][1];
  int i,j,k;
  Pa[0][0]=a;
  Pa[1][0]=b;
  Pa[2][0]=c;
  Pa[3][0]=1;

  Ta[0][0]=1;
  Ta[0][1]=0;
  Ta[0][2]=0;
  Ta[0][3]=a;
  Ta[1][0]=0;
  Ta[1][1]=cos(theta);
  Ta[1][2]=-sin(theta);
  Ta[1][3]=b;
  Ta[2][0]=0;
  Ta[2][1]=sin(theta);
  Ta[2][2]=cos(theta);
  Ta[2][3]=c;
  Ta[3][0]=0;
  Ta[3][1]=0;
  Ta[3][2]=0;
  Ta[3][3]=1;
   for(i=0;i<4;i++)
   { cout<<"\n";
     for(j=0;j<4;j++)
     {
       cout<<Ta[i][j]<<"\t";
     }
   }

 for(i=0;i<4;i++)
  {
    for(j=0;j<1;j++)
    { Ph[i][j]=0;
      for(k=0;k<4;k++)
      {
         Ph[i][j]+=Ta[i][k]*Pa[k][j];
      }
    }
  }
  for(i=0;i<4;i++)
  { cout<<"\n";
    for(j=0;j<1;j++)
    {
      cout<<Ph[i][j]<<"\t";
    }
  }
    cout<<"\nglobal coordinates :\n";
    cout<<"x = "<<Ph[0][0]<<" y = "<<Ph[1][0]<<" Z = "<<Ph[2][0]<<"\n";
}


int main()
{

 int x,y,z;
 float deg;
 cout<<"enter x,y,z ";
 cin>>x>>y>>z;
 cout<<"\nenter rotation angle in radians ";
 cin>>deg;
 cout<<"Local coordinates are \n";
 cout<<"x = "<<x<<" y = "<<y<<" Z = "<<z<<"\n";
 local_global(x,y,z,deg);
 return 0;

}
