#include <stdio.h>
#include <math.h>
struct point{
	int x;
	int y;
};
int main()
{
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		double max=0;
		int i,j,ax,ay,bx,by;
		double dist;
		scanf("%d",&n);
		struct point points[n];
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&points[i].x,&points[i].y);
		}
		for (i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
				dist=sqrt(((points[i].x-points[j].x)*(points[i].x-points[j].x))+((points[i].y-points[j].y)*(points[i].y-points[j].y)));
				if (dist>max)
				{
					max=dist;
					ax=points[i].x;
					ay=points[i].y;
					bx=points[j].x;
					by=points[j].y;
				}
			}
		}
		if (ax<bx)
			printf("%d %d %d %d\n",ax,ay,bx,by);
		else
			printf("%d %d %d %d\n",bx,by,ax,ay);
	}
	return 0;
}
