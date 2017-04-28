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

void deletetree(struct node* p)
{
	if (p==NULL)
		return;
	deletetree(p->lchild);
	deletetree(p->rchild);
	printf("Deleting node %d\n",p->info);
	free(p);
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
	deletetree(root);
	return 0;
}
