#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char s[4];
	int info;
	int f;
	struct node *link;
};
typedef struct node NODE;

NODE *addatbeg(NODE *start, int data, char str[])
{
	NODE *tmp,*p;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp -> info = data;
	tmp->f=0;
	strcpy(tmp->s,str);
	tmp -> link = tmp;
	start = tmp;
	return start;
}

NODE *addatend(NODE *start, int data, char str[])
{
	NODE *tmp;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp -> info = data;
	tmp->f=0;
	strcpy(tmp->s,str);
	NODE *p;
	p = start;
	while (p -> link != start)
		p = p -> link;
    	tmp -> link = p -> link;
	p -> link = tmp;
	return start;
}

NODE *addafter(NODE *start, int data, char item[], char str[])
{
	NODE *tmp,*p;
	p = start;
	while (p -> link != start)
	{
		if (strcmp(p -> s, item)==0)
		{
			tmp = (NODE *) malloc(sizeof(NODE));
			tmp -> info = data;
			tmp->f=0;
			strcpy(tmp->s,str);
			tmp -> link = p -> link;
			p -> link = tmp;
			return start;
		}
		p = p -> link;
	}
	if (strcmp(p -> s, item)==0)
	{
		start = addatend(start,data,str);               //this is case when element is found at last number
		return start;
	}

	printf("%s not found in the list!\n",item);
	return start;
}

void search(NODE *start, char item[], int q)
{
	NODE *p = start;
	while (p -> link != start)
	{
		if (strcmp (p ->s,item)==0)
		{
			p->f=1;
			printf("%s\n",p->s);
			break;
		}
		p = p -> link;
	}
	q--;
	while (q--)
	{
		int n=p->info;
		if (n!=-1)
		{
			while (n--)
			{
				p=p->link;			
			}
			printf("%s\n",p->s);
		}
		else
		{
			NODE* tmp = p;
			int min=1000000000;
			NODE* minpos=NULL;
			tmp=tmp->link;
			while (tmp->link!=p)
			{
				if (tmp->f<min)
				{
					min=tmp->f;
					minpos=tmp;
				}
				tmp=tmp->link;
			}
			p=minpos;
			printf("%s\n",p->s);	
		}
		p->f=p->f+1;
	}
}

int main()
{	
	NODE *start = NULL;
	int n;
	scanf("%d",&n);
	char a[4],b[4];
	int hop;
	scanf("%s%s%d",a,b,&hop);
	start=addatbeg(start,hop,a);
	n--;
	while (n--)
	{
		scanf("%s%s%d",a,b,&hop);
		start=addafter(start,hop,b,a);
	}
	int q;
	scanf("%d",&q);
	scanf("%s",a);
	search(start,a,q);
	return 0;
}
