/* Create a recursive function to traverse throught all elements of a list and remove the largest number in the list after the current element */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* link;
};

struct node* addatbeg(struct node* head, int k)
{
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=k;
	tmp->link=NULL;
	head=tmp;
	return head;
}

struct node* addatend(struct node* head, int k)
{
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=k;
	tmp->link=NULL;
	struct node* p=head;
	while (p->link!=NULL)
	{
		p=p->link;
	}
	p->link=tmp;
	return head;
}

struct node* fnc(struct node* head)
{
	if (head==NULL || head->link==NULL) //base
	{
		return head;
	}
	struct node *tmp=head,*maxnode=tmp->link,*maxprev=tmp;
	int max=tmp->link->info;
	while (tmp->link!=NULL)  //find max after p
	{
		if (tmp->link->info>max)
		{
			max=tmp->link->info;
			maxnode=tmp->link;
			maxprev=tmp;
		}
		tmp=tmp->link;
	}
	maxprev->link=maxnode->link;  
	free(maxnode); //remove max
	fnc(head->link);  //recurse
	return head;
}

void display(struct node* head)
{
	struct node* p=head;
	while (p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->link;
	}
}

int main()
{
	int n,i,tmp;
	struct node* head=NULL;
	scanf("%d",&n);
	scanf("%d",&tmp);
	head=addatbeg(head,tmp);
	for (i=1;i<n;i++)
	{
		scanf("%d",&tmp);
		head=addatend(head,tmp);
	}
	head=fnc(head);
	display(head);
	return 0;
}
