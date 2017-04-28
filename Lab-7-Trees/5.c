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

int countleaves(struct node* p)
{
	if (p==NULL)
		return 0;
	if (p->lchild==NULL && p->rchild==NULL)
		return 1;
	else
		return countleaves(p->lchild)+countleaves(p->rchild);
}

int main()
{
	struct node *root=NULL;
	int n,i,tmp;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		root=insert(root,tmp);
	}
	int leaves=countleaves(root);
	printf("%d\n",leaves);
	return 0;
}
