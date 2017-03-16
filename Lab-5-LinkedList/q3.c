#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

struct node
{
	int info;
	struct node *link;
};
typedef struct node NODE;

NODE *addatbeg(NODE *start, int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

NODE *addatend(NODE *start, int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	NODE *p;
	p=start;
	while (p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}

NODE *create_list(NODE *start)
{
	int i,n,data;
	printf("Enter the number of nodes!\n");
	scanf("%d",&n);
	start=NULL;
	if (n==0)
		return start;
	printf("Enter the element to be inserted!\n");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for (i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted!\n");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}

void display(NODE *start)
{
	NODE *p;
	if (start==NULL)
	{
		printf("List is empty!\n");
		return;
	}
	p=start;
	printf("The list is\n");
	while (p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}

int main() {
	NODE *start=NULL;
	start=create_list(start);
	display(start);

	int stack[MAX];
	int popped,top=-1;	
	NODE *tmp=start;
	NODE *p;
	while (tmp!=NULL && tmp->link!=NULL)
	{
		push(stack, &top, tmp->link->info);
		p=tmp->link;
		tmp->link=p->link;
		free(p);
		tmp=tmp->link;
	}

	while (!isEmpty(top))
	{
		popped=pop(stack, &top);
		start=addatend(start, popped);
	}

	display(start);
	return 0;
}
