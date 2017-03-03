#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};
typedef struct node NODE;

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
		p=p->next;
	}
	printf("\n\n");
}

NODE *addtoempty(NODE *start, int data)
{
	NODE*tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}

NODE *addatbeg(NODE *start, int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
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
	while (p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}

NODE *addafter(NODE *start, int data, int item)
{
	NODE *tmp,*p;
	tmp=(NODE *)malloc(sizeof(NODE));
	tmp->info=data;
	p=start;
	while (p!=NULL)
	{
		if (p->info==item)
		{
			tmp->prev=p;
			tmp->next=p->next;
			if (p->next!=NULL)
				p->next->prev=tmp;
			p->next=tmp;
			return start;
		}
		p=p->next;
	}
	printf("%d not found in the list!\n",item);
	return start;
}

NODE *addbefore(NODE *start, int data, int item)
{
	NODE *tmp,*p;
	if (start==NULL)
	{
		printf("List is empty!\n");
		return start;
	}
	if (start->info==item)
	{
		tmp=(NODE *)malloc(sizeof(NODE));
		tmp->info=data;
		tmp->prev=NULL;
		tmp->next=start;
		start=tmp;
		return start;
	}
	p=start;
	while (p!=NULL)
	{
		if (p->info==item)
		{
			tmp=(NODE *)malloc(sizeof(NODE));
			tmp->info=data;
			tmp->prev=p->prev;
			tmp->next=p;
			p->prev->next=tmp;
			p->prev=tmp;
			return start;
		}
		p=p->next;
	}
	printf("Item %d not found in the list!\n",item);
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
	start=addtoempty(start,data);
	for (i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted!\n");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}

NODE *del(NODE *start, int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	if (start==NULL)
	{
		printf("List is empty!\n");
		return start;
	}
	if (start->next==NULL)
	{
		if (start->info==data)
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return start;
		}
		else
		{
			printf("Element %d not found!\n",data);
			return start;
		}
	}
	if (start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return start;	
	}
	tmp=start->next;
	while (tmp->next!=NULL)
	{
		if (tmp->info==data)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return start;
		}
		tmp=tmp->next;
	}
	if (tmp->info==data)
	{
		tmp->prev->next=NULL;
		free(tmp);
		return start;
	}
	printf("Element %d not found!\n", data);
	return start;
}

NODE *reverse(NODE *start)
{
	NODE *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while (p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	printf("List reversed\n");
	return start;
}

int main()
{
	NODE *start=NULL;
	int choice,data,item;
	while (1)
	{
		printf("1. Create a list\n");
		printf("2. Display\n");
		printf("3. Add to empty list\n");
		printf("4. Add at beginning\n");
		printf("5. Add at end\n");
		printf("6. Add after\n");
		printf("7. Add before\n");
		printf("8. Delete\n");
		printf("9. Reverse\n");
		printf("10. Quit\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1: start=create_list(start);break;
			case 2: display(start);break;
			case 3:
				printf("Enter the element to be inserted!!\n");
				scanf("%d",&data);
				addtoempty(start,data);break;
			case 4:
				printf("Enter the element to be inserted!\n");
				scanf("%d",&data);
				start=addatbeg(start,data);break;
			case 5:
				printf("Enter the element to be inserted\n");
				scanf("%d",&data);
				start=addatend(start,data);break;
			case 6:
				printf("Enter the element to be inserted!\n");
				scanf("%d",&data);
				printf("Enter the element after which to insert!\n");
				scanf("%d",&item);
				start=addafter(start,data,item);break;
			case 7:
				printf("Enter the element to be inserted!\n");
				scanf("%d",&data);
				printf("Enter the element before which to insert!\n");
				scanf("%d",&item);
				start=addbefore(start,data,item);break;
			case 8:
				printf("Enter the element to be deleted!\n");
				scanf("%d",&data);
				start=del(start,data);break;
			case 9:
				start=reverse(start);break;
			case 10:
				exit(1);
			default:
				printf("Please enter a choice from 1 to 10!\n");
		}
	}
	return 0;
}
