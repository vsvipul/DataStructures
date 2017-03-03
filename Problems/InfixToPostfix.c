#include<stdio.h>
#include<string.h>

int preference(char a)
{
    if(a == '^')
        return 5;
    else if(a == '/')
        return 4;
    else if(a == '*')
        return 3;
    else if(a == '+')
        return 2;
    else
        return 1;
}

int push(char stack[],int top, char c)
{
    if(top == 100)
    {
        printf("Stack overflown\n");
        return top;
    }
    else
    {
        top++;
        stack[top] = c;
        return top;
    }
}

int pop(char stack[],int top)
{
    top--;
    return top;
}

int isempty(int top)
{
    if(top == -1)
        return 1;
    else
        return 0;
}

char showtop(char stack[],int top)
{
    return stack[top];
}

int main()
{
    while(1)
    {
        char e[100],temp,s[100],a[100];
        int top=-1,n,i,l=0,j,k;

        printf("Enter the expression\nUse only single digits...... don't type numbers containing 2 digits\n");
        scanf("%s",e);

        for(i=0;e[i]!='\0';i++)                 //determining length of expression
            l++;

        e[l]=')';                               //add ) at the end of expression
        l++;
        top = push(s,top,'(');                  //push ) to empty stack

        i=0;j=0;
        while(!isempty(top))
        {
            if(e[i] >=48 && e[i] <= 57)
            {
                a[j] = e[i];
                j++;
                i++;
            }
            else if(e[i] == '(')
            {
                top = push(s,top,'(');
                i++;
            }
            else if(e[i] == ')')
            {
                while(showtop(s,top) != '(')
                {
                    temp = showtop(s,top);
                    a[j] = temp;
                    top = pop(s,top);
                    j++;
                }
                top = pop(s,top);
                i++;
            }
            else
            {
                while( showtop(s,top) != '(' && preference(showtop(s,top)) >= preference(e[i]) )
                {
                    temp = showtop(s,top);
                    a[j] = temp;
                    top = pop(s,top);
                    j++;
                }
                top = push(s,top,e[i]);
                i++;
            }
        }
        for(k=0;k<j;k++)
            printf("%c",a[k]);
        printf("\n");
    }
}
