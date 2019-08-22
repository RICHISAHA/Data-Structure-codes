#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct data *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
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
            top=push(top,x);
            break;
        case 2:
            top=pop(top);
            break;
        case 3:
            printf("\n Stack is ");
            top=display(top);
            break;
        case 4:
            exit(0);
        default:
            printf("\n Enter the correct choice from the menu.");
        }
    }
}
struct stack *push(struct stack *top,int x)
{
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->data=x;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
}
struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
        if(top==NULL)
            printf("\n Stack is empty.");
        else
        {
            printf("\n Stack is: ");
            while(ptr!=NULL)
            {
                printf(" %d",ptr->data);
                ptr=ptr->next;
            }
        }
        return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if(top==NULL)
        printf("\n Stack underflow.");
    else
    {
        top=top->next;
        printf("\n The value popped is %d",ptr->data);
        free(ptr);

    }
    return top;
}
