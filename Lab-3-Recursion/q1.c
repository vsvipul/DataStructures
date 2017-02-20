//     Using recursion search for an integer ‘a’ in a 1-D integer array. Return -1 if the element is not found.

#include <stdio.h>

int search(int arr[],int n,int k)
{
	if (n==-1)
		return -1;
	if(arr[n]==k)
		return n;
	else
		return search(arr,n-1,k);
	return -1;
}

int main()
{
	int n,i,k;
	scanf("%d %d",&n,&k);
	int arr[n];
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int res=search(arr,n-1,k);
	if (res==-1)
	{
		printf("%d not found at any position\n",k);
		return 0;
	}
	printf("%d found at position %d\n",k,res+1);
	return 0;
}
