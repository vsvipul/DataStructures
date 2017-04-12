#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char info;
	struct node* link;
};

int isEmpty(struct node* top)
{
	return (top == NULL);
}

void push(struct node** top, int item)
{
	struct node *tmp;
	tmp= (struct node *)malloc(sizeof(struct node));
	if (tmp==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	tmp->info=item;
	tmp->link=*top;
	*top=tmp;
}

int pop(struct node** top)
{
	int item;
	struct node* tmp;
	if (isEmpty(*top))
	{
		printf("Stack Underflow\n");
		return -1;
	}
	tmp=*top;
	item=tmp->info;
	*top=(*top)->link;
	free(tmp);
	return item;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[1000001];
        struct node* top=NULL;
        int i,flag=1,j;
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(')
            {
                push(&top,s[i]);
            }
            else if(s[i]==')')
            {
                if(isEmpty(top))
                {
                    printf("NO\n");
                    flag=0;
                    break;
                }
                else
                {
                    pop(&top);
                }
            }
        }
        if(flag!=0)
        {
            if(isEmpty(top))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
