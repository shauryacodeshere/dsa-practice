#include<stdio.h>
#define MAX 5

struct circular
{
    int front,rear,arr[MAX];
}c;

void display();

void enqueue()
{
    int n;
    if((c.rear+1)%MAX==c.front)
    printf("\nArray is full");

    else
    {
        printf("\nEnter the element:");
        scanf("%d",&n);

        if(c.rear==-1 && c.front==-1)
        {
            c.front=0;
            c.rear=0;
        }

        else
        {
            c.rear=(c.rear+1)%MAX;
        }

        c.arr[c.rear]=n;
        display();
    }

}


void dequeue()
{
    int n;
    if(c.rear==-1 && c.front==-1)
    printf("\nArray is Empty");

    else
    {
        n=c.arr[c.front];
        printf("\nDeleted element:%d",n);

        if(c.rear==c.front)
        {
            c.rear=-1,c.front=-1;
        }

        else
        {
            c.front=(c.front+1)%MAX;
        }
    }

}

void display()
{
    
    if(c.rear==-1 && c.front==-1)
    printf("\nArray is Empty");

    else
    {
        int i=c.front;
        printf("\nCircular queue elements:\n");
        while( i!=c.rear)
        {
            printf("%d\n",c.arr[i]);
            i=(i+1)%MAX;
        }
        printf("%d",c.arr[i]);
    }

}

int main()
{
    int choice=0;
    c.front=-1,c.rear=-1;

    while(choice!=4)
    {
        printf("\n-----MENU-----");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice); 

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting");
                break;

            default:
                printf("\nInvalid choice");
                break;

            
        } 
    }
    return 0;
}