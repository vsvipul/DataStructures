#include <stdio.h>

#define MAX 100
#define temp 0
#define perm 1
#define infinity 99999
#define NIL -1

int n;
int adj[MAX][MAX];
int pre[MAX];
int pathlength[MAX];
int status[MAX];

void create_graph()
{
	int i,maxedges,origin,dest,wt;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	maxedges=n*(n-1);
	for (i=1;i<=maxedges;i++)
	{
		printf("Enter edge %d (-1, -1 to quit) : ",i);
		scanf("%d %d",&origin,&dest);
		if (origin==-1 && dest==-1)
			break;
		printf("Enter weight for this age is: ");
		scanf("%d",&wt);
		if (origin>=n || dest>=n || origin<0 || dest<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[origin][dest]=wt;
	}
}

void findpath(int s, int v)
{
	int i,u;
	int path[MAX];
	int shortdist=0;
	int count=0;
	while (v!=s)
	{
		count++;
		path[count]=v;
		u=pre[v];
		shortdist+=adj[u][v];
		v=u;
	}
	count++;
	path[count]=s;
	printf("Shortest path is: ");
	for (i=count;i>=1;i--)
		printf("%d ",path[i]);
	printf("Shortest distance is : %d\n",shortdist);
}

int min_temp()
{
	int i;
	int min=infinity;
	int k=NIL;
	for (i=0;i<n;i++)
	{
		if (status[i]==temp && pathlength[i]<min)
		{
			min=pathlength[i];
			k=i;
		}
	}
	return k;
}

void dijkstra(int s)
{
	int i,current;
	for (i=0;i<n;i++)
	{
		pre[i]=NIL;
		pathlength[i]=infinity;
		status[i]=temp;
	}
	pathlength[s]=0;
	while (1)
	{
		current=min_temp();
		if (current==NIL)
			return;
		status[current]=perm;
		for (i=0;i<n;i++)
		{
			if (adj[current][i]!=0 && status[i]==temp)
			{
				if (pathlength[current]+adj[current][i] < pathlength[i])
				{
					pre[i]=current;
					pathlength[i]=pathlength[current]+adj[current][i];
				}
			}
		}
	}
}

int main()
{
	int s,v;
	create_graph();
	printf("Enter source vertex: ");
	scanf("%d",&s);
	dijkstra(s);
	while (1)
	{
		printf("Enter destination vertex (-1 to quit): ");
		scanf("%d",&v);
		if (v==-1)
			break;
		if (v<0 && v>=n)
		{
			printf("This vertex does not exist\n");
			continue;
		}
		else if (v==s)
			printf("Source and destination vertex are same\n");
		else if (pathlength[v]==infinity)
			printf("There is no path from source to destination vertex\n");
		else
			findpath(s,v);
	}
}
