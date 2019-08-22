#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int A[MAX],top=-1;
int push(int A[],int x);
int pop(int A[]);
void display(int A[]);
int main()
{
    int x,ch;
    while(1)
    {
        printf("\n MENU ");
        printf("\n Enter 1 for push, 2 for pop, 3 for display and 4 to exit. ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter the value to be pushed in the stack.");
            scanf("%d",&x);
            push(A,x);
            break;
        case 2:
            pop(A);
            break;
        case 3:
            printf("\n Stack is ");
            display(A);
            break;
        case 4:
            exit(0);
        default:
            printf("\n Enter the correct choice from the menu.");
        }
    }
}
int push(int A[],int x)
{
    if(top==MAX-1)
        printf("\n Stack overflow.");
    else
    {
        A[++top]=x;
        return top;
    }
}
int pop(int A[])
{
    if(top==-1)
        printf("\n Stack underflow.");
    else
    {
         printf("\n data popped is %d",A[top]);
         top--;
         return top;
    }
}
void display(int A[])
{
    int i;
    if(top==-1)
        printf("\n Stack empty.");
    else
    {
        for(i=top;i>=0;i--)
            printf(" %d",A[i]);
    }
}
