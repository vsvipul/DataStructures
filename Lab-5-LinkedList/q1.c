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

int displaysum(NODE * tmp, int sum)
{
	if (tmp==NULL)
		return sum;
	else
		sum+=tmp->info;
	tmp=tmp->link;
	return displaysum(tmp,sum);
}

int main() {
	NODE *start=NULL;
	start=create_list(start);
	printf("The sum of the elements of linked list is: %d\n\n",displaysum(start,0));
	return 0;
}
