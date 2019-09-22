#include<Stdio.h>
int main()
{
    int arr[10];
    int i,n,ele,pos;
    printf("enter size of array");
    scanf("%d",&n);
    printf("enter array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
    {
        if(arr[i+1]>arr[i])
        {
            ele=arr[i];
            pos=i+1;
             for(i=pos-1;i<n-1;i++)
                 arr[i]=arr[i+1];
             n=n-1;
        }

    }
   for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
