#include<stdio.h>
int main ()
{
 int num,ld,sum=0;
 printf("enter any number ");
 scanf("%d",&num);
 while(num>0)
 {
   ld=num%10;
   sum+=ld;
   num=num/10;
   if(num==0 && sum>9)
     {
       num=sum;
       sum=0;
     }
 }
 printf("the generic root of %d is %d",num,sum);
}
