#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *top;
    struct node *next;
};

struct node *push (struct node *top,int value)
{
   struct node *pnew;
   pnew=(struct node *) malloc(sizeof(struct node));
   pnew->data=value;
   pnew->next=NULL;

   if(top==NULL)
   {
    top=pnew;
    return pnew;
   }

   else{
    pnew->next=top;
    top=pnew;
    return pnew;
   }
}

struct node *pop(struct node *top)
{
    struct node * n2d;
    n2d=(struct node*)malloc(sizeof(struct node));
    
    if(top==NULL)
    {
        printf("\nStack is empty");
        return top;
    }

    else
    {
        top=n2d;
        top=top->next;
        free(n2d);
        return top;
    }
}

void display(struct node *top)
{
    if(top==NULL)
    {
        printf("\nStack is empty");
    }

    else
    {
        printf("\nElements of the stack are:");

        while (top!=NULL)
        {
            printf("%d\n",top->data);
            top=top->next;
        }
    }
}

int main()
{
    struct node *list;
    int choice, val;
    list=NULL;

    while(choice!=4)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d",&choice);



        switch(choice)
        {
            case 1:
            printf("Enter the value to be pushed:");
            scanf("%d",&val);
            list=push(list,val);
            display(list);
            break;

            case 2:
            pop(list);
            display(list);
            break;

            case 3:
            display(list);
            break;

            case 4:
            printf("\nExiting...");

            default:
            printf("Invalid choice.");


        }
    }


    
}


