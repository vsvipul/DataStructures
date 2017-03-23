#include <stdlib.h>
#include <stdio.h>
 
void swap (int *a, int *b)
{
	int tmp=*b;
	*b=*a;
	*a=tmp;
} 

int partition(int arr[], int l, int r)
{
	int pivot=arr[r];
	int j,i=l-1;
	for (j=l; j<=r; j++)
	{
		if (arr[j]<=pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	return i;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi=partition(arr, l, r);
	quicksort(arr, l, pi-1);
	quicksort(arr, pi+1, r);
    }
}
 
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	printf("The sorted array is:\n");
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
