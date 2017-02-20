// Using recursion search for an integer ‘a’ in a 2-D integer array. Return -1 if the element is not found.

#include <stdio.h>

int search(int n,int m,int arr[n][m],int i,int j,int k)
{
	if (i==n)
		return 0;
    if (arr[i][j]==k)
    	return 1;
    else
    {
    	if (j<m-1)
    	{
    		j++;
    		return search(n,m,arr,i,j,k);
    	}
    	else
    	{
    		i++;j=0;
    		return search(n,m,arr,i,j,k);
    	}
    }
}

int main()
{
	int i,k,j,n,m;
	scanf("%d%d%d",&n,&m,&k);
	int arr[n][m];
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
		scanf("%d",&arr[i][j]);
		}
	}
	if (!search(n,m,arr,0,0,k))
		printf("%d not found at any position\n",k);
	else
		printf("%d is present in array\n",k);
	return 0;
}
