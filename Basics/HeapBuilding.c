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

void minheapify(int arr[], int i, int n)
{
	int smallest,tmp;
	int l=2*i;
	int r=2*i+1;
	if (l<=n && arr[l]<arr[i])
		smallest=l;
	else
		smallest=i;
	if (r<=n && arr[r]<arr[smallest])
		smallest=r;
	if (smallest!=i)
	{
		tmp=arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=tmp;
		minheapify(arr,smallest,n);
	}
}

void buildmaxheap(int arr[], int n)
{
	int i;
	for (i=n/2;i>=1;i--)
		maxheapify(arr,i,n);
}

void buildminheap(int arr[], int n)
{
	int i;
	for (i=n/2;i>=1;i--)
		minheapify(arr,i,n);
}

void display(int arr[], int n)
{
	int i;
	for (i=1;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n+1];
	for (i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	display(arr,n);
	buildminheap(arr,n);
	display(arr,n);
	buildmaxheap(arr,n);
	display(arr,n);
	return 0;
}
