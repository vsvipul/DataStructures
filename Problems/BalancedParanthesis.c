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
	return (top==-1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000001],stack[1000001];
        int top=-1,n,i,flag=1,j;
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(')
            {
                top=push(stack,top,s[i]);
            }
            else if(s[i]==')')
            {
                if(isempty(top))
                {
                    printf("NO\n");
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
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
