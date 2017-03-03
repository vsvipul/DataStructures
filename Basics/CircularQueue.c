#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int isFull(int front, int rear)
{
	return ((rear==MAX-1 && front==0)||(front==rear+1));
}

int isEmpty(int front)
{
	return (front==-1);
}

void insert(int cqueue[], int *front, int *rear, int item)
{
	if (isFull(*front,*rear))
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (*front==-1)
		*front=0;
	if (*rear==MAX-1)
		*rear=0;
	else
		*rear=*rear+1;
	cqueue[*rear]=item;
}

int del(int cqueue[], int *front, int *rear)
{
	int item;
	if (isEmpty(*front))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=cqueue[*front];
	if (*front==*rear) //1 element only
	{
		*front=-1;
		*rear=-1;
	}
	else if (*front==MAX-1)
		*front=0;
	else
		*front=*front+1;
	return item;
}

int peek(int cqueue[], int front)
{
	if (isEmpty(front))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	return cqueue[front];
}

void display(int cqueue[], int front, int rear)
{
	int i;
	if (isEmpty(front))
	{
		printf("\nQueue is Empty\n");
		return;
	}
	printf("\nQueue Elements: \n\n");
	i=front;
	if (front<=rear)
	{
		while (i<=rear)
		{
			printf("%d ",cqueue[i]);
			i++;
		}
	}
	else
	{
		while (i<=MAX-1)
		{
			printf("%d ",cqueue[i]);
			i++;
		}
		i=0;
		while (i<=rear)
		{
			printf("%d ",cqueue[i]);
			i++;
		}
	}
	printf("\n\n");
}

int main()
{
	int cqueue[MAX];
	int rear=-1;
	int front=-1;
	int choice,item;
	while (1)
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display element at the front\n");
		printf("4. Display all elements of the circular queue\n");
		printf("5. Quit\n");
		printf("Enter You Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&item);
				insert(cqueue,&front,&rear,item);break;
			case 2:
				item=del(cqueue,&front,&rear);
				printf("\nThe deleted item is: %d\n\n",item);break;
			case 3:
				printf("\nItem at the front is: %d\n\n",peek(cqueue,front));break;
			case 4:
				display(cqueue,front,rear);break;
			case 5:
				exit(1);
			default:
				printf("\nPlease enter a choice between 1 and 5\n\n");
		}
	}
	return 0;
}
