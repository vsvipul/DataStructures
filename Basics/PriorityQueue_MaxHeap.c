#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
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

void display(int arr[], int n)
{
	int i;
	for (i=1;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int maximum(int arr[])
{
	return arr[1];
}

int extract_max(int arr[], int* n)  //pqdequeue
{
	if (*n==0)
	{
		printf("Cant remove element as queue is empty\n");
		return -1;
	}
	int max=arr[1];
	arr[1]=arr[*n];
	*n=*n-1;
	maxheapify(arr,1,*n);
	return max;
}

void increase_value(int arr[], int i, int val)
{
	if (val<arr[i])
	{
		printf("New value less than current value\n");
		return;
	}
	arr[i]=val;
	int temp;
	while (i>1 && arr[i/2]<arr[i])
	{
		temp=arr[i/2];
		arr[i/2]=arr[i];
		arr[i]=temp;
		i/=2;
	}
}

void insert(int arr[], int val, int* n)  //pqenqueue
{
	*n=*n+1;
	arr[*n]=-1;
	increase_value(arr,*n,val);
}

int main()
{
	int n=0,i,choice,num;
	int arr[MAX];
	while (1)
	{
		printf("\n1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print max\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter number to enqueue: ");
				scanf("%d",&num);
				insert(arr,num,&n);
				break;
			case 2:
				num=extract_max(arr,&n);
				printf("Number dequeued is: %d\n",num);
				break;
			case 3:
				num=maximum(arr);
				printf("Max element is: %d\n",num);
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Enter a choice between 1 and 4\n");
		}
	}	
	return 0;
}
