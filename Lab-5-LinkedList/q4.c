#include <stdio.h>
#include <stdlib.h>

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

int main() 
{
	NODE *start1=NULL;
	NODE *start2=NULL;
	printf("For first list:\n");
	start1=create_list(start1);
	printf("For second list:\n");
	start2=create_list(start2);

	NODE *p1=start1,*p2=start2,*tmp,*tmp2;
	while (p1!=NULL && p2!=NULL)
	{
		tmp=p1->link;
		tmp2=p2->link;
		p1->link=p2;
		p2->link=tmp;
		start2=tmp2;
		p2=tmp2;
		p1=p1->link->link;
	}
	
	printf("First list:\n");
	display(start1);
	printf("Second list:\n");
	display(start2);	
	return 0;
}
