#include<stdio.h>

int stack[100],choice,n,top,x,i;
void push()
{
    if(top>=n-1)
        printf("\nSTACK is over flow");
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
        printf("\n Stack is under flow");
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
    }
    else
        printf("\n The STACK is empty");

}

int main()
{
    top=-1;
    printf("\nEnter the size of STACK:");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n***************************");
    printf("\n 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n THANK YOU!! ");
                break;
            }
            default:
            {
                printf ("\n wrong choice entered");
            }

        }
    }
    while(choice!=4);

}



