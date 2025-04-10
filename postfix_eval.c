#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50

struct stack
{
    int top;
   int arr[MAX];
}s;

void push(int c)
{
    s.arr[++s.top]=c;   
}

int pop()
{
    if(s.top==-1)
    {
        return 0;
    }
    
    else
    {
        return s.arr[s.top--];   
    }
          
    
}

int eval(char *exp)
{
    int i=0;
    while (exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i]-'0');
        }

        else
        {
            int x1=pop();
            int x2=pop();
            switch(exp[i])
            {
                case '+':
                push (x2+x1);
                break;

                case '-':
                push (x2-x1);
                break;

                case '/':
                push (x2/x1);
                break;

                case '*':
                push (x2*x1);
                break;
            }



        }
        i++;

    }
    return pop();
     
}


int main()
{
    s.top=-1;
    char exp[MAX];
    printf("\nEnter the postfix expression:");
    scanf("%s",exp);
    printf("Result: %d\n", eval(exp));
    return 0;
}