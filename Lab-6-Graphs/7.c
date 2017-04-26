#include <stdio.h>
#include <string.h>

#define MAX 100
#define initial 1
#define visited 2
#define finished 3
int n;
int adj[MAX][MAX];
int state[MAX];

void dfs(int v)
{
	int i;
	printf("%d ",v);
	state[v]=visited;
	for (i=0;i<=n;i++)
	{
		if (adj[v][i]==1 && state[i]==initial)
			dfs(i);
	}
	state[v]=finished;
}

void dftraversal()
{
	int v;
	for (v=0;v<=n;v++)
		state[v]=initial;
//	printf("Enter starting vertex for dfs.\n");
//	scanf("%d",&v);
	v=0;
	dfs(v);
	for (v=0;v<=n;v++)
	{
		if (state[v]==initial)
			dfs(v);
	}
	printf("\n");
}

int main()
{
	int i,j,x;
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
	dftraversal();
	return 0;
}
