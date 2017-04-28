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

void preorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	printf("%d_",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	preorder(ptr->lchild);
	printf("%d_",ptr->info);
	preorder(ptr->rchild);
}

void postorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	preorder(ptr->lchild);
	preorder(ptr->rchild);
	printf("%d_",ptr->info);
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
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
}
