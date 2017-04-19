#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void create_graph(int adj[MAX][MAX], int* n)
{
	int i,maxedges,src,dest,tmp;
	printf("Enter number of vertices: ");
	scanf("%d",&tmp);
	*n=tmp;
	maxedges=tmp*(tmp-1);
	for (i=1;i<=maxedges;i++)
	{
		printf("Enter edge %d ((-1,-1) to quit): ",i);
		scanf("%d%d",&src,&dest);
		if (src==-1 && dest==-1)
			break;
		if (src>=tmp||dest>=tmp||src<0||dest<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[src][dest]=1;
	}
}

void insert_edge(int n, int adj[MAX][MAX], int src, int dest)
{
	if (src<0||src>=n||dest<0||dest>=n)
	{
		printf("Destination or source vertex does not exist\n");
		return;
	}
	adj[src][dest]=1;
}

void del_edge(int n, int adj[MAX][MAX], int src, int dest)
{
	if (src<0||src>=n||dest<0||dest>=n)
	{
		printf("Destination or source vertex does not exist\n");
		return;
	}
	adj[src][dest]=0;
}

void display(int n, int adj[MAX][MAX])
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
}

int main()
{
	int adj[MAX][MAX];
	int choice, source, dest, n;
	create_graph(adj, &n);
	while (1)
	{
		printf("1. Insert an Edge\n");
		printf("2. Delete an edge\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter an edge to be inserted: ");
				scanf("%d%d",&source,&dest);
				insert_edge(n,adj,source,dest);
				break;
			case 2:
				printf("Enter an edge to be deleted: ");
				scanf("%d%d",&source,&dest);
				del_edge(n,adj,source,dest);
				break;
			case 3:
				display(n,adj);
				break;
			case 4:
				exit(1);
			default:
				printf("Please enter a choice from 1 to 4.\n");
				break;
		}
	}
}
