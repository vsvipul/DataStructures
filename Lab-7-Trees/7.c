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

struct node* create(int in[], int post[], int is, int ie, int ps, int pe)
{
	if (ps>pe)
		return NULL;
	struct node* tmp=(struct node*)malloc(sizeof(struct node));
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	tmp->info=post[pe];
	int pos,i;
	for (i=is;i<=ie;i++)
	{
		if (in[i]==tmp->info)
		{
			pos=i;
			break;
		}
	}
	tmp->lchild=create(in,post,is,pos-1,ps,ps+pos-is-1);
	tmp->rchild=create(in,post,pos+1,ie,pe+pos-ie,pe-1);
	return tmp;	
}

struct node* buildtree(int in[], int post[], int n)
{
	return create(in,post,0,n-1,0,n-1);
}

void preorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	printf("%d ",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

int main()
{
	struct node *root=NULL;
	int n,i,tmp;
	scanf("%d",&n);
	int in[n];
	int post[n];
	for (i=0;i<n;i++)
		scanf("%d",&in[i]);
	for (i=0;i<n;i++)
		scanf("%d",&post[i]);
	root=buildtree(in,post,n);
	preorder(root);
	printf("\n");
	return 0;
}
