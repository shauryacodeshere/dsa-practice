#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;  
}*first=NULL;

int count(struct node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

void insert(struct node *p,int pos,int ndata)
{
    struct node *t;
    t=(struct node *) malloc(sizeof(struct node));
    t->data=ndata;

    if(pos<0 || pos>count(first))
        return;

    if(pos==0)
    {
        t->next=first;
        first=t;
    }

    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    } 
}


void delete(struct node *p,int pos)
{
    struct node *t=NULL;
    int x;

    if(pos<1||pos>count(first))
    return;

    if(pos==1)
    {
        t=first;
        x=first->data;
        first=first->next;
        free(t);
        
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            t=p;
            p=p->next;
        }
        t->next=p->next;
        x=p->data;
        free(p);
        
    }

}


void display(struct node *p)
{
   
    
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    
}

int main()
{
    int choice;

    while(choice!=4)
    {

    printf("\n----MENU----");
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);

    int position;

    switch(choice)
    {
        case 1:
        {
            int num;
            printf("\nEnter the position:");
            scanf("%d",&position);
            printf("\nEnter the data:");
            scanf("%d",&num);
            insert(first,position,num);
            break;
        }

        case 2:
        printf("\nEnter the position:");
        scanf("%d",&position);
        delete(first,position);
        display(first);
        break;

        case 3:
        display(first);
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
