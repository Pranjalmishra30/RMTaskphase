#include<stdio.h>

int gen_root(int n)
{
 int ld,sum=0;
 while(n>0)
 {
  ld=n%10;
  sum+=ld;
  n=n/10;
 }

 if(sum>9)
  {
   n=sum;
   gen_root(n);
  }
 else
  return (sum);
}
int main ()
{
 int num,sum;
 printf("enter any number ");
 scanf("%d",&num);
 sum=gen_root(num);
 printf("the generic root of %d is %d",num,sum);
}
