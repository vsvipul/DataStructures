#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#define infinity 99999
#define NIL -1
int n;
int adj[MAX][MAX];
int state[MAX];
int distance[MAX];
int pre[MAX];
int queue[MAX],front=-1,rear=-1;

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

void bfs(int v)
{
	int i;
	enqueue(v);
	state[v]=waiting;
	distance[v]=0;
	pre[v]=NIL;
	while (!isEmpty())
	{
		v=dequeue();
		state[v]=visited;
		for (i=0;i<n;i++)
		{
			if (adj[v][i]==1 && state[i]==initial)
			{
				enqueue(i);
				state[i]=waiting;
				pre[i]=v;
				distance[i]=distance[v]+1;
			}
		}
	}
	printf("\n");
}

void bftraversal()
{
	int v;
	for (v=0;v<n;v++)
	{
		state[v]=initial;
		pre[v]=NIL;
		distance[v]=infinity;
	}
//	printf("Enter starting vertex for bfs: ");
//	scanf("%d",&v);
	v=0;
	bfs(v);
}

int main()
{
	int i,j,x,v,count,path[MAX]; //make n global
	scanf("%d",&n);
	int inp[n+1];
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=n;j++)
		{
			adj[i][j]=0;
		}
	}
	for (i=0;i<=n;i++)
	{
		scanf("%d",&inp[i]);
	}
	for (i=0;i<=n;i++)
	{
		if (i-2>=0)
			adj[i][i-2]=1;
		if (i+1<=n)
			adj[i][i+1]=1;
		if (i+2<=n)
			adj[i][i+2]=1;
		if (i+5<=n)
			adj[i][i+5]=1;
		if (i+10<=n)
			adj[i][i+10]=1;

	}
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	bftraversal();
	while (1)
	{
		printf("Enter destination vertex (-1 to quit): ");
		scanf("%d",&v);
		if (v<-1 || v>n) //v>n-1 originally
		{
			printf("Destination vertex does not exist\n");
			continue;
		}
		if (v==-1)
			break;
		if (distance[v]==infinity)
		{
			printf("No path from start vertex to destination vertex\n");
			continue;
		}
		else
			printf("Shortest distance is %d\n",distance[v]);
		count=0;
		while (v!=NIL)
		{
			count++;
			path[count]=v;
			v=pre[v];
		}
		printf("Shortest path is: ");
		for (i=count;i>1;i--)
			printf("%d->",path[i]);
		printf("%d\n",path[i]);
	}
	return 0;
}
