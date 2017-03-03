#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int isFull(int rear)
{
	return (rear==MAX-1);
}

int isEmpty(int front, int rear)
{
	return (front==-1 || front==rear+1);
}

void insert(int queue[], int *front, int *rear, int item)
{
	if (isFull(*rear))
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (*front==-1)
		*front=0;
	*rear=*rear+1;
	queue[*rear]=item;
}

int del(int queue[], int *front, int *rear)
{
	int item;
	if (isEmpty(*front,*rear))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=queue[*front];
	*front=*front+1;
	return item;
}

int peek(int queue[], int front, int rear)
{
	if (isEmpty(front,rear))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	return queue[front];
}

void display(int queue[], int front, int rear)
{
	int i;
	if (isEmpty(front,rear))
	{
		printf("\nQueue is Empty\n");
		return;
	}
	printf("\nQueue Elements: \n\n");
	for (i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n\n");
}

int main()
{
	int queue[MAX];
	int rear=-1;
	int front=-1;
	int choice,item;
	while (1)
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display element at the front\n");
		printf("4. Display all elements of the queue\n");
		printf("5. Quit\n");
		printf("Enter You Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&item);
				insert(queue,&front,&rear,item);break;
			case 2:
				item=del(queue,&front,&rear);
				printf("\nThe deleted item is: %d\n\n",item);break;
			case 3:
				printf("\nItem at the front is: %d\n\n",peek(queue,front,rear));break;
			case 4:
				display(queue,front,rear);break;
			case 5:
				exit(1);
			default:
				printf("\nPlease enter a choice between 1 and 5\n\n");
		}
	}
	return 0;
}
