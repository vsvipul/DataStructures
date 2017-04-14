#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(char arr[][5], int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	char left[n1][5],right[n2][5];
	for (i=0;i<n1;i++)
		strcpy(left[i],arr[l+i]);
	for (j=0;j<n2;j++)
		strcpy(right[j],arr[m+1+j]);
	i=0;j=0;k=l;
	while (i<n1 && j<n2)
	{
		if (strcmp(left[i],right[j])<=0)
		{
			strcpy(arr[k],left[i]);
			i++;
		}
		else
		{
			strcpy(arr[k],right[j]);
			j++;
		}
		k++;
	}
	while (i<n1)
	{
		strcpy(arr[k],left[i]);
			i++;
		k++;
	}		
	while (j<n2)
	{
		strcpy(arr[k],right[j]);
			j++;
		k++;
	}	
}

void mergesort(char arr[][5], int l, int r)
{
	if (l<r)
	{
		int m=l+(r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);		
	}
}

int bisearch(char arr[][5], int l, int r, char str[])
{
	int mid=(l+r)/2;
	while (r-l>=1)
	{
		mid=(l+r)/2;
		if (strcmp(arr[mid],str)>=0)
			r=mid;
		else
			l=mid+1;
	}
	if (strcmp(arr[r],str)==0)
		return 1;
	return 0;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	char arr[n][5];
	for (i=0;i<n;i++)
		scanf("%s",arr[i]);
	mergesort(arr, 0, n-1);
	int q;
	char str[5];
	scanf("%d",&q);
	while (q--)
	{
		scanf("%s",str);
		printf("%d\n",bisearch(arr,0,n-1,str));
	}		
	return 0;
}
