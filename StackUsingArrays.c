#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int isFull(int top)
{
	return (top==MAX-1);
}

int isEmpty(int top)
{
	return (top==-1);
}

void push(int stack[], int *top, int item)
{
	if (isFull(*top))
	{
		printf("Stack Overflow!\n");
		return;
	}
	*top=*top+1;
	stack[*top]=item;
}

int pop(int stack[], int *top)
{
	int item;
	if (isEmpty(*top))
	{
		printf("Stack Underflow!\n");
		exit(1);
	}
	item=stack[*top];
	*top=*top-1;
	return item;
}

int peek(int stack[], int top)
{
	if (isEmpty(top))
	{
		printf("Stack Underflow!\n");
		exit(1);
	}
	return stack[top];
}

void display(int stack[], int top)
{
	int i;
	if (isEmpty(top))
	{
		printf("\nStack is Empty\n");
		return;
	}
	printf("\nStack Elements: \n\n");
	for (i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	printf("\n");
}

int main()
{
	int stack[MAX];
	int top=-1;
	int choice,item;
	while (1)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display the top element\n");
		printf("4. Display the stack\n");
		printf("5. Quit\n");
		printf("Enter You Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the element to be pushed: ");
				scanf("%d",&item);
				push(stack,&top,item);break;
			case 2:
				item=pop(stack,&top);
				printf("\nThe element popped is: %d\n\n",item);break;
			case 3:
				printf("\nItem at the top is: %d\n\n",peek(stack,top));break;
			case 4:
				display(stack,top);break;
			case 5:
				exit(1);
			default:
				printf("\nPlease enter a choice between 1 and 5\n\n");
		}
	}
	return 0;
}
