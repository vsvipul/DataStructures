#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node* search(struct node *ptr, int key)
{
	if (ptr==NULL)
	{
		return NULL;
	}
	else if (key<ptr->info)
		return search(ptr->lchild,key);
	else if (key>ptr->info)
		return search(ptr->rchild,key);
	else
		return ptr;
}

struct node* insert(struct node* ptr, int key)
{
	if (ptr==NULL)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->info=key;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
	}
	else if (key<ptr->info)
		ptr->lchild=insert(ptr->lchild,key);
	else if (key>ptr->info)
		ptr->rchild=insert(ptr->rchild,key);
	else
		printf("Duplicate key\n");
	return ptr;
}

int main()
{
	struct node *root=NULL,*p;
	int n,i,tmp,q;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		root=insert(root, tmp);
	}
	scanf("%d",&q);
	for (i=0;i<q;i++)
	{
		scanf("%d",&tmp);
		p=search(root, tmp);
		if (p==NULL)
			printf("n\n");
		else
			printf("y\n");
	}
}
