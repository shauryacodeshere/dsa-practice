#include<stdio.h>
#define MAX 10

struct queue
{
    int rear,front,arr[MAX];
}q;

void display();

void enqueue()
{
    int n;
    if(q.rear==MAX-1)
    printf("\nQueue is full");
    

    else
    {
        printf("\nEnter the element:");
        scanf("%d",&n);
        q.arr[++q.rear]=n;
        display();
    }
}

void dequeue()
{
    int n;

    if(q.front>q.rear)
    printf("\nQueue is empty");

    else
    {
        n=q.arr[q.front];
        display();  
        q.front++;    
    }
}

void display()
{
    
    if(q.front>q.rear)
    printf("\nQueue is empty");

    else
    {
        printf("\nCurrent queue:\n");
        for(int i=q.rear;i>=q.front;i--)
        {
            printf("%d\t",q.arr[i]);
        }
    }
}


int main()
{
    q.rear=-1;
    q.front=0;
    int choice;
    while(choice!=4)
    {
    printf("\n-----MENU-----");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);    
    switch (choice)
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
        printf("\nExiting the program\n");
        break;
    
    default:
        printf("\nInvalid choice\n");
        break;
    }

    }

return 0;    

}
