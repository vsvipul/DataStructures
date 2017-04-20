#include <stdio.h>

void maxheapify(int arr[], int i, int n)
{
	int largest,tmp;
	int l=2*i;
	int r=2*i+1;
	if (l<=n && arr[l]>arr[i])
		largest=l;
	else
		largest=i;
	if (r<=n && arr[r]>arr[largest])
		largest=r;
	if (largest!=i)
	{
		tmp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=tmp;
		maxheapify(arr,largest,n);
	}
}

void buildmaxheap(int arr[], int n)
{
	int i;
	for (i=n/2;i>=1;i--)
		maxheapify(arr,i,n);
}

void display(int arr[], int n)
{
	int i;
	for (i=1;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void heapsort(int arr[], int n)
{
	int heapsize=n;
	buildmaxheap(arr,n);
	int i,temp;
	for (i=n;i>=2;i--)
	{
		temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp;
		heapsize--;
		maxheapify(arr,1,heapsize);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n+1];
	for (i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	display(arr,n);
	heapsort(arr,n);
	display(arr,n);
	return 0;
}
