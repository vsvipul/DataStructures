#include <stdio.h>

int main()
{
	int t,n,i,sum;
	scanf("%d",&t);
	while (t--)
	{
		sum=0;
		scanf("%d",&n);
		int arr[n];
		for (i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			if (arr[i]<0) arr[i]*=(-1);
			sum+=arr[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
