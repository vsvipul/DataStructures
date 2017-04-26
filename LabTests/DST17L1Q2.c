#include <stdio.h>

int main()
{
	int t,n,i,k,l,res;
	scanf("%d",&t);
	while (t--)
	{
		res=0;
		scanf("%d",&n);
		int arr[n];
		for (i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		scanf("%d%d",&k,&l);
		for (i=0;i<l;i++)
		{
			if (i+k>=n) break;
			res+=arr[k+i];
		}
		printf("%d\n",res);
	}
	return 0;
}
