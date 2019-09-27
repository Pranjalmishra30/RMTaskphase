#include<stdio.h>
int main()
{
 int n,ld,sum=0;
 printf("enter any number ");
 scanf("%d",&n);
 while(n>0)
 {
  ld=n%10;
  sum+=ld;
  n=n/10;
  if(n==0 && sum>9)
  {
     n=sum;
     sum=0;
   }

 }
 printf("the generic root of %d is %d",n,sum);

}

