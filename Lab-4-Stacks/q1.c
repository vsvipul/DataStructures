#include<stdio.h>

int push(int a[],int n,int *top)
{
    int i,temp;
    temp=*top;
    temp++;
    a[temp]=n;
    *top=temp;
    return 0;
}

void pop(int a[],int top)
{

}

int isempty(int a[],int top)
{

}

int findmax(int curr)
{
    return ((curr>=0)*curr+(curr<0)*0);
}

int main()
{
    int top=-1,a[100],currmax,t,n,l,i;

    printf("Here we are implementing stack with some specific function\n");
    printf("Current f(s)=0\nEnter the number of elements you want to push to stack\n");
    scanf("%d",&t);

    currmax=0;
    while(t--)
    {
        printf("Enter the number\n");
        scanf("%d",&n);

        l=findmax(currmax);
        push(a,n+l,&top);
        currmax=n+l;

        printf("Now the stack is:\n");
        //printf("top= %d\n",top);
        for(i=0;i<=top;i++)
            printf("%d ",a[i]);
        printf("\n");

        printf("and current f(s) is %d\n\n",n+l);
    }
}
