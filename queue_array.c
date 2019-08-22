#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int A[MAX],front=-1,rear=-1;
void insert();
int delete();
void display();
int main()
{
    int val,ch;
    while(1)
    {
        printf("\n MENU ");
        printf("\n Enter 1 for insert, 2 for delete, 3 for display and 4 to exit. ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
           val=delete();
           if(val!=-1)
            printf("\n The deleted element is %d",val);
            break;
        case 3:
            printf("\n Queue is ");
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Enter the correct choice from the menu.");
        }
    }
}
void insert()
{
    int num;
    printf("\n Enter the value to be inserted.");
    scanf("%d",&num);
    if(rear==MAX-1)
        printf("\n overflow.");
    else if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear++;
    A[rear]=num;
}
int delete()
{
    int val;
    if(front==-1||front>rear)
    {


        printf("\n underflow.");
        return -1;
    }
    else
    {
        val=A[front];
        front++;
         if(front>rear)
            front=rear=-1;
         return val;
    }
}
void display()
{
    int i;
    if(front==-1||front>rear)
        printf("\n empty.");
    else
    {
        for(i=front;i<=rear;i++)
            printf(" %d",A[i]);
    }
}
