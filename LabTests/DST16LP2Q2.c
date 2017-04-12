#include <stdio.h>

void solve(int arr[], int n, int k, int count, int sum, int i, int *ans)
{
	int j;
	if (sum>=40 && count==k)
	{
		*ans=*ans+1;
		return;
	}
	else
	{
		for (j=i+1;j<n;j++)
		{
			count++;sum+=arr[j];
			solve(arr,n,k,count,sum,j,ans); 
			count--;sum-=arr[j]; //backtrack
		}
	}
	return;
}

int main(){
	int t,n,k,i;
	int ans;
	scanf("%d",&t);
	while (t--)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		int arr[n];
		for (i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for (i=0;i<n;i++)
			solve(arr,n,k,1,arr[i],i,&ans);
		printf("%d\n",ans);
	}
	return 0;
}
