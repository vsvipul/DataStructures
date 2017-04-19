#include <stdio.h>
#include <stdlib.h>

struct edge
{
	struct vertex* destvertex;
	struct edge* nextedge;
};

struct vertex
{
	int info;
	struct vertex* nextvertex;
	struct edge* firstedge;
};

struct vertex* insertvertex(struct vertex* start, int u)
{
	struct vertex *tmp,*p;
	tmp=malloc(sizeof(struct vertex));
	tmp->info=u;
	tmp->nextvertex=NULL;
	tmp->firstedge=NULL;
	if (start==NULL)
	{
		start=tmp;
		return start;
	}
	p=start;
	while (p->nextvertex!=NULL)
		p=p->nextvertex;
	p->nextvertex=tmp;
	return start;
}

struct vertex* deletevertex(struct vertex* start, int u)
{
	struct vertex *tmp, *p;
	struct edge *q,*r;
	if (start==NULL)
	{
		printf("No vertices to be deleted\n");
		return start;
	}
	if (start->info==u) //first vertex to be deleted 
	{
		tmp=start;
		start=tmp->nextvertex;
	}
	else
	{
		p=start;
		while (p->nextvertex->info!=u)
			p=p->nextvertex;
		if (p->nextvertex==NULL)
		{
			printf("Vertex not found");
			return start;
		}
		else
		{
			tmp=p->nextvertex;
			p->nextvertex=tmp->nextvertex;
		}
	}
	//now free all edges from vertex before dfreeing vertex
	q=tmp->firstedge;
	while (q!=NULL)
	{
		r=q;
		q=q->nextedge;
		free(r);
	}
	free(tmp);
	return start;
}

struct vertex* deleteincomingedges(struct vertex* start, int u)
{
	struct vertex *p;
	struct edge *q, *tmp;
	p=start;
	while (p!=NULL)
	{
		if (p->firstedge==NULL) //empty vertex
		{
			p=p->nextvertex;
			continue;
		}
		if (p->firstedge->destvertex->info==u) //first edge of a vertex to be deleted
		{
			tmp=p->firstedge;
			p->firstedge=tmp->nextedge;
			free(tmp);
			continue;
		}
		q=p->firstedge;
		while (q->nextedge!=NULL)
		{
			if (q->nextedge->destvertex->info==u)
			{
				tmp=q->nextedge;
				q->nextedge=tmp->nextedge;
				free(tmp);
				continue;
			}
			q=q->nextedge;
		}
		p=p->nextvertex;
	}
	return start;
}

struct vertex* findvertex(struct vertex* start, int u)
{
	struct vertex *p, *loc;
	p=start;
	while (p!=NULL)
	{
		if (p->info==u)
		{
			loc=p;
			return loc;
		}
		p=p->nextvertex;
	}
	loc=NULL;
	return loc;
}

struct vertex* insertedge(struct vertex* start, int u, int v)
{
	struct vertex *locu,*locv;
	struct edge *tmp,*p;
	locu=findvertex(start, u);
	locv=findvertex(start, v);
	if (locu==NULL || locv==NULL)
	{
		printf("Start or end vertex not present. Insert that first.\n");
		return start;
	}
	tmp=malloc(sizeof(struct edge));
	tmp->destvertex=locv;
	tmp->nextedge=NULL;
	if (locu->firstedge==NULL) //first edge in that vertex
	{
		locu->firstedge=tmp;
		return start;
	}
	p=locu->firstedge;
	while (p->nextedge!=NULL)
		p=p->nextedge;
	p->nextedge=tmp;
	return start;
}

struct vertex* deleteedge(struct vertex* start, int u, int v)
{
	struct vertex *locu;
	struct edge *tmp,*q;
	locu=findvertex(start, u);
	if (locu==NULL)
	{
		printf("Start vertex not present\n");
		return start;
	}
	if (locu->firstedge==NULL)
	{
		printf("Edge not present\n");
		return start;
	}
	if (locu->firstedge->destvertex->info==v)
	{
		tmp=locu->firstedge;
		locu->firstedge=tmp->nextedge;
		free(tmp);
		return start;
	}
	q=locu->firstedge;
	while (q->nextedge!=NULL)
	{
		if (q->nextedge->destvertex->info==u)
		{
			tmp=q->nextedge;
			q->nextedge=tmp->nextedge;
			free(tmp);
			return start;
		}
		q=q->nextedge;
	}
	printf("This edge is not present in the graph\n");
	return start;
}

void display(struct vertex* start)
{
	struct vertex *p;
	struct edge *q;
	p=start;
	while (p!=NULL)
	{
		printf("%d ",p->info);
		q=p->firstedge;
		while (q!=NULL)
		{
			printf(" %d",q->destvertex->info);
			q=q->nextedge;
		}
		printf("\n");
		p=p->nextvertex;
	}
}

int main()
{
	struct vertex* start=NULL;
	int choice,u,src,dest;
	while (1)
	{
		printf("1. Insert a vertex\n");
		printf("2. Insert an edge\n");
		printf("3. Delete a vertex\n");
		printf("4. Delete an edge\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter a vertex to be inserted: ");
				scanf("%d", &u);
				start=insertvertex(start,u);
				break;
			case 2:
				printf("Enter an edge to be inserted: ");
				scanf("%d %d",&src,&dest);
				start=insertedge(start, src, dest);
				break;
			case 3:
				printf("Enter a vertex to be deleted: ");
				scanf("%d",&u);
				start=deleteincomingedges(start, u);
				start=deletevertex(start, u);
				break;
			case 4:
				printf("Enter an edge to be deleted: ");
				scanf("%d %d",&src,&dest);
				start=deleteedge(start,src,dest);
				break;
			case 5:
				display(start);
				break;
			case 6:
				exit(1);
			default:
				printf("Please enter a choice between 1 and 6\n");
		}
	}	
}
