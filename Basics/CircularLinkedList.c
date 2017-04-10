#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node NODE;

NODE *addtoempty(NODE *start,int data)
{
    NODE *tmp;
    tmp = (NODE *)malloc(sizeof(NODE));
    start = tmp;
    tmp -> info = data;
    tmp -> link = start;
    return start;
}

void display(NODE *start)
{
	NODE *p;
	if (start == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	p = start;
	printf("The list is\n");
	while (p -> link != start)
	{
		printf("%d ",p -> info);
		p = p -> link;
	}
	printf("%d \n",p -> info);
	return;
}

void search(NODE *start, int item)
{
	NODE *p = start;
	int pos = 1;
	while (p -> link != start)
	{
		if (p -> info == item)
		{
			printf("Item %d found at pos %d !\n",item,pos);
			return;
		}
		p = p -> link;
		pos++;
	}
	printf("Item %d not found in the list!\n",item);
}

NODE *addatbeg(NODE *start, int data)
{
	NODE *tmp,*p;
	tmp = (NODE *)malloc(sizeof(NODE));
	p = start;
	while (p -> link != start)
	{
		p = p -> link;
	}
	tmp -> info = data;
	tmp -> link = start;
	start = tmp;
	p -> link = start;

	return start;
}

NODE *addatend(NODE *start, int data)
{
	NODE *tmp;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp -> info = data;
	NODE *p;
	p = start;
	while (p -> link != start)
		p = p -> link;
    	tmp -> link = p -> link;
	p -> link = tmp;
	return start;
}

NODE *addafter(NODE *start, int data, int item)
{
	NODE *tmp,*p;
	p = start;
	while (p -> link != start)
	{
		if (p -> info == item)
		{
			tmp = (NODE *) malloc(sizeof(NODE));
			tmp -> info = data;
			tmp -> link = p -> link;
			p -> link = tmp;
			return start;
		}
		p = p -> link;
	}
	if (p -> info == item)
	{
		start = addatend(start,data);               //this is case when element is found at last number
		return start;
	}

	printf("%d not found in the list!\n",item);
	return start;
}

NODE *addbefore(NODE *start, int data, int item)
{
	NODE *tmp,*p;
	if (start == NULL)
	{
		printf("List is empty!\n");
		return start;
	}
	if (start -> info == item)
	{
		start = addatbeg(start,data);           //this is case when first element itself is the number looking for.
		return start;
	}

	p = start;
	while (p -> link != start)
	{
		if (p -> link -> info == item)
		{
			tmp = (NODE *)malloc(sizeof(NODE));
			tmp -> info = data;
			tmp -> link = p -> link;
			p -> link = tmp;
			return start;
		}
		p = p -> link;
	}
	printf("Item %d not found in the list!\n",item);
	return start;
}

NODE *create_list(NODE *start)
{
	int i,n,data;
	printf("Enter the number of nodes!\n");
	scanf("%d",&n);
	start = NULL;
	if (n == 0)
		return start;
	printf("Enter the element to be inserted!\n");
	scanf("%d",&data);
	start = addtoempty(start,data);
	for (i=2 ; i<=n ; i++)
	{
		printf("Enter the element to be inserted!\n");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}

NODE *del(NODE *start, int data)
{
	NODE *tmp,*p;
	p = start;
	tmp = (NODE *)malloc(sizeof(NODE));
	if (start == NULL)
	{
		printf("List is empty!\n");
		return start;
	}
	if (start -> info == data)
	{
		while (p -> link != start)
		{
			if (p -> link -> info == data)
			{
				tmp = p -> link;
				printf("tmp: %d",tmp->info);
				p -> link = tmp -> link;
				free(tmp);
				return start;
			}
			p = p -> link;
		}
		tmp = p -> link;
		p -> link = tmp -> link;
		start = tmp -> link;
		return start;
	}
	
	while (p -> link != start)
	{
		if (p -> link -> info == data)
		{
			tmp = p -> link;
			printf("tmp: %d",tmp->info);
			p -> link = tmp -> link;
			free(tmp);
			return start;
		}
		p = p -> link;
	}
	printf("Element %d not found!\n", data);
	return start;
}

void count(NODE *start)
{
    NODE *p;
    p = start;
    if(start == NULL)
    {
        printf("Number of elements in list= %d\n\n",0);
        return;
    }
    int res = 1;
    while (p ->link != start)
    {
        res++;
        p = p -> link;
    }
    printf("Number of elements in list= %d\n\n",res);
}

int main()
{
	NODE *start = NULL;
	int choice,data,item,pos;
	while (1)
	{
		printf("\n0. Create a linked list\n");
		printf("1. Display\n");
		printf("2. Count\n");
		printf("3. Search\n");
		printf("4. Add to empty linked list\n");
		printf("5. Add at beginning\n");
		printf("6. Add at end\n");
		printf("7. Add after\n");
		printf("8. Add before\n");
		printf("9. Delete\n");
		printf("10. Quit\n\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 0: start=create_list(start);break;
			case 1: display(start);break;
			case 2: count(start);break;
			case 3:
				printf("Enter the element to be searched!!\n");
				scanf("%d",&data);
				search(start,data);break;
            		case 4:
                		printf("Enter the element to be inserted in the empty linked list:\n");
                		scanf("%d",&data);
                		start=addtoempty(start,data);break;
			case 5:
				printf("Enter the element to be inserted!\n");
				scanf("%d",&data);
				start=addatbeg(start,data);break;
			case 6:
				printf("Enter the element to be inserted\n");
				scanf("%d",&data);
				start=addatend(start,data);break;
			case 7:
				printf("Enter the element to be inserted!\n");
				scanf("%d",&data);
				printf("Enter the element after which to insert!\n");
				scanf("%d",&item);
				start=addafter(start,data,item);break;
			case 8:
				printf("Enter the element to be inserted!\n");
				scanf("%d",&data);
				printf("Enter the element before which to insert!\n");
				scanf("%d",&item);
				start=addbefore(start,data,item);break;
			case 9:
				printf("Enter the element to be deleted!\n");
				scanf("%d",&data);
				start=del(start,data);break;
			case 10:
				exit(1);
			default:
				printf("Invalid input\nPlease enter a choice from 1 to 12!\n");
		}
	}
	return 0;
}
