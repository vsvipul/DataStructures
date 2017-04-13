#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* link;
};
typedef struct node NODE;

struct node* merge(struct node* p1, struct node* p2)
{
	struct node* start_merged,*q;
	if (p1->info <= p2->info)
	{
		start_merged=p1;
		p1=p1->link;
	}
	else
	{
		start_merged=p2;
		p2=p2->link;
	}
	q=start_merged;
	while (p1!=NULL && p2!=NULL)
	{
		if (p1->info <= p2->info)
		{
			q->link=p1;
			q=q->link;
			p1=p1->link;
		}
		else
		{
			q->link=p2;
			q=q->link;
			p2=p2->link;
		}
	}
	if (p1!=NULL)
		q->link=p1;
	else
		q->link=p2;
	return start_merged;
}

struct node* divide(struct node* p)
{
	struct node *q,*start_second;
	q=p->link->link;
	while (q!=NULL)
	{
		p=p->link;
		q=q->link;
		if (q!=NULL)
			q=q->link;
	}
	start_second=p->link;
	p->link=NULL;
	return start_second;
}

struct node* merge_sort(struct node* start)
{
	struct node *start_first, *start_second, *start_merged;
	if (start!=NULL && start->link!=NULL)
	{
		start_first=start;
		start_second=divide(start);
		start_first=merge_sort(start_first);
		start_second=merge_sort(start_second);
		start_merged=merge(start_first, start_second);
		return start_merged;
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


int main(){
	struct node* start=NULL;
	start=create_list(start);
	start=merge_sort(start);
	display(start);
	return 0;
}
