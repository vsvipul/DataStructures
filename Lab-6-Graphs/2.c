#include <stdio.h>
#include <stdlib.h>

struct node
{
	int dest;
	struct node* next;
};

struct list
{
	struct node* head;
};

struct graph
{
	int v;
	struct list* arr;
};

struct node* newNode(int dest)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->dest=dest;
	newnode->next=NULL;
	return newnode;
}

struct graph* creategraph(int v)
{
	struct graph* g= (struct graph*)malloc(sizeof(struct graph));
	g->v=v;
	g->arr= (struct list*)malloc(v*sizeof(struct list));
	int i;
	for (i=0;i<v;i++)
	{
		g->arr[i].head=NULL;
	}
	return g;
}

void addedge(struct graph* g, int src, int dest)
{
	struct node* newnode=newNode(dest);
	newnode->next=g->arr[src].head;
	g->arr[src].head=newnode;
	// since undirected
	newnode=newNode(src);
	newnode->next=g->arr[dest].head;
	g->arr[dest].head=newnode;
}

void printgraph(struct graph* g)
{
	int v;
	for (v=0;v<g->v;v++)
	{
		struct node* crawl=g->arr[v].head;
		printf("\n Adjacenct list of vertex %d\n head ", v);
		while (crawl)
		{
			printf("-> %d",crawl->dest);
			crawl=crawl->next;
		}
		printf("\n");
	}
}

int main()
{
	int i,v;
	scanf("%d",&v);
	struct graph* g= creategraph(v);
	for (i=0;i<v;i++)
	{
		if (i-2>=0)
			addedge(g,i-2,i);
		if (i+1<v)
			addedge(g,i,i+1);
		if (i+2<v)
			addedge(g,i,i+2);
		if (i+5<v)
			addedge(g,i,i+5);
		if (i+10<v)
			addedge(g,i,i+10);
	}
	printgraph(g);
	return 0;
}
