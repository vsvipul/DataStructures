#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void push(char stack[], int *top, char item)
{
	if (*top==MAX-1)
	{
		printf("Stack Overflow!\n");
		return;
	}
	*top=*top+1;
	stack[*top]=item;
}

char pop(char stack[], int *top)
{
	if (*top==-1)
	{
		printf("Stack is empty!\n");
		exit(1);
	}
	char item=stack[*top];
	*top=*top-1;
	return item;
}

int main()
{
	char str[MAX];
	char stack[MAX];
	int top=-1;
	int i;
	printf("Enter the string: ");
	scanf("%[^\n]",str);
	for (i=0;i<strlen(str);i++)
	{
		push(stack,&top,str[i]);
	}
	for (i=0;i<strlen(str);i++)
	{
		str[i]=pop(stack,&top);
	}
	printf("Reversed String is: %s\n",str);
}
