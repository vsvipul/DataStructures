#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;

NODE *show(NODE *start)
{
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p = start;
	printf("\nYour linked list is :");
	while(p -> next != NULL)
	{
		printf("%d -> ",p -> data);
		p = p -> next;
	}
	printf("%d\n",p -> data);
	return start;
}

NODE *add_before(NODE *start, int data)
{
	NODE *tmp;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp -> data = data;
	tmp -> next = start;
	start = tmp;
	return start;
}

NODE *delete(NODE *start, int count)
{
	int n=0,m=0;
	NODE *p,*q,*r;
	p = (NODE *)malloc(sizeof(NODE));
	q = (NODE *)malloc(sizeof(NODE));
	r = (NODE *)malloc(sizeof(NODE));
	p = start;
	q = start;
	r = start;

	while(n != count && p -> next != NULL)
	{
		p = p -> next;
		n++;
	}
	while(m != count-1 && q -> next != NULL)
	{
		q = q -> next;
		m++;
	}

	if(count > n)
	{	
		printf("Enter correct Node number\n\n");
		return start;
	}
	
	else if(p == start)
	{
		p = p -> next;
		start = p;
		free(r);
		return start;
	}
	else
	{
		q -> next = p -> next;
		free(p);
		return start;
	}
	
}
	

NODE *add_at_end(NODE *start, int data)
{
	NODE *tmp,*p;

	tmp = (NODE *)malloc(sizeof(NODE));
	p = (NODE *)malloc(sizeof(NODE));

	tmp -> data = data;
	tmp -> next = NULL;

	if(start == NULL)
	{
		start = tmp;
		return start;
	}

	else
	{
		p = start;
		while(p -> next != NULL)
		{
			p = p -> next;
		}
		p -> next = tmp;
		return start;
	}
}

NODE *append(NODE *start, NODE *start1)
{
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p = start;
	while(p -> next != NULL)
		p = p -> next;

	p -> next = start1;
	return start;
}

NODE *reverse_alternate(NODE *start)
{
	int count=1,deleted_till_now = 0;
	NODE *p, *start1;
	start1 = NULL;							//start1 is new linked list head pointer

	p = (NODE *)malloc(sizeof(NODE));
	p = start;

	while(p -> next != NULL)
	{
		if(count%2 == 0)
		{
			start1 = add_before(start1 , p -> data);
			p = p -> next;					//else p will become dangling pointer
			delete(start, count-1-deleted_till_now);	//pos of elements change after deleteion delete_till_now keeps its track
			deleted_till_now ++;
			count++;
			continue;
		}
		count++;
		p = p -> next;	
	}
	
	start = append(start,start1);					// append linked list 1 to linked list 2
	return start;
}
		
		
int main()
{
	int x,a;
	NODE *start;

	start = NULL;	

	printf("This is the prgoram to reverse alternate node of a given link list and append them to end of linked list\n\nSelect an option:\n");
	while(1)
	{
		printf("1. Insert at end\n");
		printf("2. Insert at beginning\n");
		printf("3. Delete NODE\n");
		printf("4. Reverse alternate and append at last\n");
		printf("5. Show the linked list\n");
		printf("6. Exit\n");

		scanf("%d",&x);

		if(x == 1)
		{
			printf("Enter the number you want to add: ");
			scanf("%d",&a);
			start = add_at_end(start,a);
		}
		else if(x == 2)
		{
			printf("Enter the number you want to add: ");
			scanf("%d",&a);
			start = add_before(start,a);
		}
		else if(x == 3)
		{
			printf("Enter the NODE number (indexed at 0) you want to delete: ");
			scanf("%d",&a);
			start = delete(start, a); 
		}
		else if (x == 4)
			start = reverse_alternate(start);
		else if(x == 5)
			start = show(start);
		else if(x==6) 
			exit(1);
		else
		{
			printf("\nEnter valid Number\n");
			continue;
		}

		printf("\n");
	}
	return 0;
}
