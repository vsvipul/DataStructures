#include <stdio.h>

int main()
{
	int sx,sy,m,t,n,i,j,res;
	scanf("%d",&t);
	while (t--)
	{
		res=0;
		scanf("%d",&n);
		int arr[n][n];
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		scanf("%d",&m);
		int temp;
		scanf("%d%d",&sx,&sy);
		int curx,cury;
		curx=sx;
		cury=sy;
		res+=arr[curx][cury];
		arr[curx][cury]=0;
		for (i=0;i<m;i++)
		{
			scanf("%d",&temp);
			if (temp==1)
			{
				if (curx>0)
				{
					curx--;
				}
			}
			else if (temp==2)
			{
				if (curx<n-1)
				{
					curx++;
				}
			}
			else if (temp==3)
			{
				if (cury<n-1)
				{
					cury++;
				}
			}
			else if (temp==4)
			{
				if (cury>0)
				{
					cury--;
				}
			}
			res+=arr[curx][cury];
			arr[curx][cury]=0;
		}
		printf("%d\n",res);
	}
	return 0;
}
