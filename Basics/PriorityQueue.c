#include <stdio.h>
#include <stdlib.h>

struct node
{
	int priority;
	int info;
	struct node* link;
}*front=NULL;

void insert(int item, int item_priority)
{
	struct node *tmp, *p;
	tmp= (struct node *)malloc(sizeof(struct node));
	if (tmp==NULL)
	{
		printf("No memory");
		return;
	}
	tmp->info=item;
	tmp->priority=item_priority;
	if (isEmpty()|| (item_priority < front->priority) )
	{
		tmp->link=front;
		front=tmp;
	}
	else
	{
		p=front;
		while (p->link!=NULL && p->link->priority <= item_priority)
			p=p->link;
		tmp->link=p->link;
		p->link=tmp;
	}
}

int del()
{
	struct node* tmp;
	int item;
	if (isEmpty())
	{
		printf("Queue Underflow");
		exit(1);
	}
	else
	{
		tmp=front;
		item=tmp->info;
		front=front->link;
		free(tmp);
	}
	return item;
}

int isEmpty()
{
	return (front==NULL);
}

void display()
{
	struct node* ptr;
	ptr=front;
	if (isEmpty())
		printf("Queue is empty");
	else
	{
		printf("Queue is: \n");
		printf("Priority 	Item\n");
		while (ptr!=NULL)
		{
			printf("%5d		%5d\n",ptr->priority,ptr->info);
			ptr=ptr->link;
		}
	}
}

int main(){
	int choice, item, item_priority;
	while (1)
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Quit\n");
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Input the item to be added in priority queue: ");
				scanf("%d", &item);
				printf("Enter its priority");
				scanf("%d",&item_priority);
				insert(item, item_priority);
				break;
			case 2:
				printf("Deleted item is %d\n",del());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Please check the choice entered!\n");
		}
	}
	return 0;
}
