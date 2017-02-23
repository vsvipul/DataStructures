//double ended queue

#include<stdio.h>

int pushattop(int a[],int *top,int *rear,int x)
{
    int temp;
    temp=*top;
    temp++;
    a[temp]=x;
    *top=temp;
}

int pushatback(int a[],int *top,int *rear,int x)
{
    int temp;
    temp=*rear;
    temp--;
    a[temp]=x;
    *rear=temp;
}

int poptop(int a[],int *top,int *rear)
{
    int temp;
    temp=*top;
    a[temp]=0;
    temp--;
    *top=temp;
}

int popback(int a[],int *top,int *rear)
{
    int temp;
    temp=*rear;
    a[temp]=0;
    temp++;
    *rear=temp;
}

int isfullback(int a[],int *top,int *rear)
{
    if(*rear<=0)
        return 1;
    else
        return 0;
}

int isfulltop(int a[],int *top,int *rear,int *full)
{
    if(*top>=*full)
        return 1;
    else
        return 0;
}

int isempty(int a[],int *top,int *rear)
{
    if(*top<*rear)
        return 1;
    else
        return 0;
}

int main()
{
    int a[10]={0},t,mid,top,rear,n,full,x,i;
    full=9;
    mid=10/2;
    top=mid-1;
    rear=mid;

    printf("Enter the number of operations you want to perform\n");
    scanf("%d",&t);
    while(t--)
    {
        printf("\nEnter your choice:\n1 for push at top\n2for push at back\n3 for pop from top\n4 for pop from back\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("\nEnter element to be pushed: ");
            scanf("%d",&x);
            if(isfulltop(a,&top,&rear,&full))
                printf("\nit is full at top can't insert more elements\n\n");
            else
                pushattop(a,&top,&rear,x);
        }
        else if(n==2)
        {
            printf("\nEnter element to be pushed: ");
            scanf("%d",&x);
            if(isfullback(a,&top,&rear))
                printf("\ncan't fill more elements at back\n\n");
            else
                pushatback(a,&top,&rear,x);
        }
        else if(n==3)
        {
            if(isempty(a,&top,&rear))
                printf("\nUnderflow condition\n\n");
            else
                poptop(a,&top,&rear);
        }
        else
        {
            if(isempty(a,&top,&rear))
                printf("\nUnderflow condition\n\n");
            else
                popback(a,&top,&rear);
        }
        printf("Look at queue : ");
        for(i=0;i<10;i++)
            printf("%d ",a[i]);
        printf("\n\n");
    }
    return 0;
}
