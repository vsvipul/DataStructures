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

struct node* del(struct node* ptr, int key)
{
	struct node *tmp,*succ;
	if (ptr==NULL)
	{
		printf("Key not found\n");
		return ptr;
	}
	if (key<ptr->info)
		ptr->lchild=del(ptr->lchild,key);
	else if (key>ptr->info)
		ptr->rchild=del(ptr->rchild,key);
	else
	{ 
		// key to be deleted is found
		if (ptr->lchild!=NULL && ptr->rchild!=NULL)
		{
			succ=ptr->rchild;
			while (succ->lchild)
				succ=succ->lchild;
			ptr->info=succ->info;
			ptr->rchild=del(ptr->rchild,succ->info);
		}
		else
		{
			tmp=ptr;
			if (ptr->lchild!=NULL)
				ptr=ptr->lchild;
			else if (ptr->rchild!=NULL)
				ptr=ptr->rchild;
			else
				ptr=NULL;
			free(tmp);
		}
	}
	return ptr;
}

void preorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	printf("%d ",ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);
}

void inorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	inorder(ptr->lchild);
	printf("%d ",ptr->info);
	inorder(ptr->rchild);
}

void postorder(struct node* ptr)
{
	if (ptr==NULL)
		return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d ",ptr->info);
}

int height(struct node* ptr)
{
	int hleft,hright;
	if (ptr==NULL)
		return 0;
	hleft=height(ptr->lchild);
	hright=height(ptr->rchild);
	if (hleft>hright)
		return 1+hleft;
	else
		return 1+hright;
}

struct node* mini(struct node* ptr)
{
	if (ptr==NULL)
		return NULL;
	else if (ptr->lchild==NULL)
		return ptr;
	else
		return mini(ptr->lchild);
}

struct node* maxi(struct node* ptr)
{
	if (ptr==NULL)
		return NULL;
	else if (ptr->rchild==NULL)
		return ptr;
	else
		return maxi(ptr->rchild);
}

int main()
{
	struct node *root=NULL,*ptr;
	int choice,k;
	while (1)
	{
		printf("\n");
		printf("1. Search\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Preorder traversal\n");
		printf("5. Inorder traversal\n");
		printf("6. Postorder traversal\n");
		printf("7. Height of tree\n");
		printf("8. Find minimum and maximum\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the key to be searched: ");
				scanf("%d",&k);
				ptr=search(root,k);
				if (ptr==NULL)
					printf("Key not present\n");
				else
					printf("Key present\n");
				break;
			case 2:
				printf("Enter the key to be inserted: ");
				scanf("%d",&k);
				root=insert(root,k);
				break;
			case 3:
				printf("Enter the key to be deleted: ");
				scanf("%d",&k);
				root=del(root,k);
				break;
			case 4:
				preorder(root);break;
			case 5:
				inorder(root);break;
			case 6:
				postorder(root);break;
			case 7:
				printf("Height of tree is %d\n",height(root));break;
			case 8:
				ptr=mini(root);
				if (ptr!=NULL)
					printf("Minimum key is %d\n",ptr->info);
				ptr=maxi(root);
				if (ptr!=NULL)
					printf("Maximum keys is %d\n",ptr->info);
				break;
			case 9:
				exit(1);
			default:
				printf("Please enter a choice between 1 and 9 \n");
		}
	}
}
