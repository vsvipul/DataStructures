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

int iscircular(NODE* start)
{
	if (start==NULL)
		return 1; //Empty list is circular
	NODE *tmp=start->link;
	while (tmp!=NULL && tmp!=start)
		tmp=tmp->link;
	return (tmp==start);
}

int main() {
	NODE *start=NULL;
	// Start with empty linked list
	// Insert elements in the simple linked list
	start=addatbeg(start, 1);
	start=addatend(start, 2);
	start=addatend(start, 3);
	// Check if circular
	if (iscircular(start))
		printf("Circular\n");	
	else
		printf("Not Circular\n");
	// Make linked list circular and then check again
	start->link->link->link=start;
	if (iscircular(start))
		printf("Circular\n");	
	else
		printf("Not Circular\n");
	return 0;
}
