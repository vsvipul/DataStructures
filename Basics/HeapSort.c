#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void heapify(int arr[], int i, int n)
{
	int l=2*i+1,r=2*i+2;
	int num=arr[i];
	while (r<n)
	{
		if (num>=arr[l] && num>=arr[r])
		{
			arr[i]=num;
			return;
		}
		else if (arr[l]>arr[r])
		{
			arr[i]=arr[l];
			i=l;
		}
		else
		{
			arr[i]=arr[r];
			i=r;
		}
		l=2*i+1;
		r=2*i+2;
	}
	if (l==n-1 && num<arr[l])
	{
		arr[i]=arr[l];
		i=l;
	}
	arr[i]=num;
}

int delroot(int arr[], int* n)
{
	int max=arr[0];
	arr[0]=arr[*n-1];
	(*n)--;
	heapify(arr,0,*n);
	return max;
}

void buildheap(int arr[], int n)
{
	int i;
	for (i=(n/2)-1;i>=0;i--)
		heapify(arr,i,n);
}

void heap_sort(int arr[], int n)
{
	int max;
	buildheap(arr,n);
	printf("Heap is : ");
	display(arr,n);
	while (n>0)
	{
		max=delroot(arr,&n);
		arr[n]=max;
	}
}

void display(int arr[], int n)
{
    int i;
    for (i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
	int i,n,arr[MAX];
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Entered list is : ");
	display(arr,n);
	heap_sort(arr,n);
	printf("Sorted array is: ");
	display(arr,n);
	return 0;
}
