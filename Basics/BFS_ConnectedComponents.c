#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX];
int state[MAX];
int label[MAX];
int queue[MAX],front=-1,rear=-1;

void create_graph()
{
	int i,maxedges,src,dest,tmp;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	maxedges=n*(n-1);
	for (i=1;i<=maxedges;i++)
	{
		printf("Enter edge %d ((-1,-1) to quit): ",i);
		scanf("%d%d",&src,&dest);
		if (src==-1 && dest==-1)
			break;
		if (src>=n||dest>=n||src<0||dest<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[src][dest]=1;
	}
}

int isFull()
{
	return (rear==MAX-1);
}

int isEmpty()
{
	return (front==-1 || front==rear+1);
}

void enqueue(int item)
{
	if (isFull())
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (front==-1)
		front=0;
	rear=rear+1;
	queue[rear]=item;
}

int dequeue()
{
	int item;
	if (isEmpty())
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=queue[front];
	front=front+1;
	return item;
}

void bfs(int v, int compnum)
{
	int i;
	enqueue(v);
	state[v]=waiting;
	while (!isEmpty())
	{
		v=dequeue();
		state[v]=visited;
		label[v]=compnum;
		printf("Vertex %d Component= %d\n",v,label[v]);
		for (i=0;i<n;i++)
		{
			if (adj[v][i]==1 && state[i]==initial)
			{
				enqueue(i);
				state[i]=waiting;
			}
		}
	}
	printf("\n");
}

void bftraversal()
{
	int v,comp=0;
	for (v=0;v<n;v++)
		state[v]=initial;
	comp++;
	bfs(0,comp);
	for (v=0;v<n;v++)
	{
		if (state[v]==initial)
		{
			comp++;
			bfs(v,comp);
		}
	}
	printf("Number of connected components = %d\n",comp);
	if (comp==1)
		printf("Connected graph\n");
	else
		printf("Not a connected graph\n");
}

int main()
{
	create_graph();
	bftraversal();
	return 0;
}
