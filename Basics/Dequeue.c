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

void insertFront(int dequeue[], int *front, int *rear, int item)
{
	if (isFull(*front,*rear))
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (*front==-1)
	{
		*front=0;
		*rear=0;
	}
	else if (*front==0)
		*front=MAX-1;
	else
		*front=*front-1;
	dequeue[*front]=item;
}

void insertRear(int dequeue[], int *front, int *rear, int item)
{
	if (isFull(*front,*rear))
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (*front==-1)
	{
		*front=0;
		*rear=0;
	}
	else if (*rear==MAX-1)
		*rear=0;
	else
		*rear=*rear+1;
	dequeue[*rear]=item;
}

int delFront(int dequeue[], int *front, int *rear)
{
	int item;
	if (isEmpty(*front))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=dequeue[*front];
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

int delRear(int dequeue[], int *front, int *rear)
{
	int item;
	if (isEmpty(*front))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=dequeue[*rear];
	if (*front==*rear) //1 element only
	{
		*front=-1;
		*rear=-1;
	}
	else if (*rear==0)
		*rear=MAX-1;
	else
		*rear=*rear-1;
	return item;
}

void display(int dequeue[], int front, int rear)
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
			printf("%d ",dequeue[i]);
			i++;
		}
	}
	else
	{
		while (i<=MAX-1)
		{
			printf("%d ",dequeue[i]);
			i++;
		}
		i=0;
		while (i<=rear)
		{
			printf("%d ",dequeue[i]);
			i++;
		}
	}
	printf("\n\n");
}

int main()
{
	int dequeue[MAX];
	int rear=-1;
	int front=-1;
	int choice,item;
	while (1)
	{
		printf("1. Insert at front end\n");
		printf("2. Insert at rear end\n");
		printf("3. Delete from front end\n");
		printf("4. Delete from rear end\n");
		printf("5. Display all elements of dequeue\n");
		printf("6. Quit\n");
		printf("Enter You Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\nEnter the element to be added: ");
				scanf("%d",&item);
				insertFront(dequeue,&front,&rear,item);break;
			case 2:
				printf("\nEnter the element to be added: ");
				scanf("%d",&item);
				insertRear(dequeue,&front,&rear,item);break;
			case 3:
				item=delFront(dequeue,&front,&rear);
				printf("\nThe deleted item is: %d\n\n",item);break;
			case 4:
				item=delRear(dequeue,&front,&rear);
				printf("\nThe deleted item is: %d\n\n",item);break;
			case 5:
				display(dequeue,front,rear);break;
			case 6:
				exit(1);
			default:
				printf("\nPlease enter a choice between 1 and 6\n\n");
		}
	}
	return 0;
}
