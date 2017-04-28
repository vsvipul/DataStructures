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

void printpathrec(struct node* p, int path[], int pathlen)
{
	if (p==NULL)
		return;
	path[pathlen]=p->info;
	pathlen++;
	if (p->lchild==NULL && p->rchild==NULL)
	{
		int i;
		for (i=0;i<pathlen;i++)
			printf("%d ",path[i]);
		printf("\n");
	}
	else
	{
		printpathrec(p->lchild,path,pathlen);
		printpathrec(p->rchild,path,pathlen);
	}
}

void printpaths(struct node* p)
{
	int path[1000];
	printpathrec(p,path,0);
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
	printpaths(root);
	return 0;
}
