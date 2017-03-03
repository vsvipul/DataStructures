#include <stdio.h>
#include <string.h>

int push(char stack[],int top,char s)
{
    {
        top++;
        stack[top]=s;
    }
    return top;
}

int pop(char stack[],int top)
{
	top--;
	return top;
}

int isempty(int top)
{
	if(top==-1)
		return 1;

	else
		return 0;
}

int main()
{
    while(1)
    {
        char s[50],stack[100];
        int top=-1,n,i,l=0,flag=1,j;
        printf("Enter the expression\n");
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
            l++;
        for(i=0;i<l;i++)
        {
            if(s[i]=='(')
            {
                top=push(stack,top,s[i]);
            }
            else if(s[i]==')')
            {
                if(isempty(top))
                {
                    printf("Not balanced\n");
                    flag=0;
                    break;
                }
                else
                {
                    top=pop(stack,top);
                }
            }
        }
        if(flag!=0)
        {
            if(isempty(top))
                printf("It is balanced\n");
            else
                printf("not balanced\n");
        }
    }

    return 0;
}
