#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

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

int identical(struct node* a, struct node* b)
{
	if (a==NULL && b== NULL)
		return 1;
	if (a!=NULL && b!=NULL)
	{
		return (a->info==b->info && identical(a->lchild,b->lchild) && identical(a->rchild,b->rchild));
	}
	return 0;
}

int main()
{
	struct node *root=NULL,*root2=NULL;
	int n,t,tmp,i;
	scanf("%d%d",&t,&n);
	while (t--)
	{
		for (i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			root=insert(root, tmp);
		}
		for (i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			root=insert(root2, tmp);
		}
		if (identical(root,root2))
			printf("y\n");
		else
			printf("n\n");
	}
	
}
