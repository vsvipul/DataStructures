#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int swapped,temp,i;
    do 
    {
        swapped=0;
        for (i=0;i<n-1;i++) 
        {
            if (arr[i]>arr[i+1]) 
            {
                swapped=1;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        n--;
    } while (swapped);
}

void InsertionSort(int arr[], int n)
{
    int i,j,key;
    for (i=1;i<n;i++) 
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void SelectionSort(int arr[], int n)
{
    int i,j,temp,minElementIndex;
    for (i=0;i<n-1;i++) 
    {
        minElementIndex=i;
        for (j=i+1;j<n;j++) 
        {
            if (arr[j]<arr[minElementIndex])
                minElementIndex = j;
        }
        if (i!=minElementIndex) 
        {
            temp=arr[i];
            arr[i]=arr[minElementIndex];
            arr[minElementIndex]=temp;
        }
    }
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	InsertionSort(arr,n); //select type of sorting here
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
}
