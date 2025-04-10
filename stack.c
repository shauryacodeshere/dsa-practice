#include<stdio.h>
#define MAX 5

struct stack
{
    int arr[MAX];
    int top;
}s;

void display();

void push()
{
    int x;
    printf("\nEnter the element:");
    scanf("%d",&x);

    if(s.top==MAX-1)
    printf("\nThe stack is full");

    else
    {
        s.arr[++s.top]=x;
        display();
    }
}

void pop()
{
    int x;
    if(s.top==-1)
    printf("\nThe stack is empty");

    else
    {
        x=s.arr[s.top--];
        printf("\nElement popped:%d\n",x);
        display();

    }
}

void display()
{

    if(s.top==-1)
    printf("\nThe stack is empty");

    else
    {
    printf("\nCurrent stack:\n");
    for(int i=s.top;i>-1;i--)
    {
        printf("%d\t",s.arr[i]);
    }
    }
}


int main()
{  
    int choice;
    s.top=-1;
    while(choice!=4)
    {
    printf("\n-----MENU-----");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);    
    switch (choice)
    {
    case 1:
        push();
        break;
    
    case 2:
        pop();
        break;
    
    case 3:
        display();
        break;
    
    case 4:
        printf("\nExiting the program\n");
        break;
    
    default:
        printf("\nInvalid choice\n");
        break;
    }

    }

return 0;
}