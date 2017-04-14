#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(char arr[][5], int l, int r)
{
	char pivot[5];
	strcpy(pivot,arr[r]);
	char tmp[5];
	int j,i=l-1;
	for (j=l;j<=r;j++)
	{
		if (strcmp(arr[j],pivot)<1)
		{
			i++;
			strcpy(tmp,arr[i]);
			strcpy(arr[i],arr[j]);
			strcpy(arr[j],tmp);
		}
	}
	return i;
}

void quicksort(char arr[][5], int l, int r)
{
    if (l<r)
    {
      int pi=partition(arr, l, r);
    	quicksort(arr, l, pi-1);
	    quicksort(arr, pi+1, r);
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
	quicksort(arr, 0, n-1);
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
