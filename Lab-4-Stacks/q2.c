#include<stdio.h>

int push(int a[],int n,int *top)
{
    int temp=*top;
    temp++;
    a[temp]=n;
    *top=temp;
}

void pop(int a[],int *top)
{
    int temp=*top;
    a[temp]=0;
    temp--;
    *top=temp;
}

int isempty1(int a[],int *top)
{
    if(*top==-1)
        return 1;
    else
        return 0;
}

int isempty2(int a[],int *top)
{
    if(*top==2)
        return 1;
    else
        return 0;
}

int isempty3(int a[],int *top)
{
    if(*top==5)
        return 1;
    else
        return 0;
}

int isfull1(int a[],int *top)
{
    if(*top==3)
        return 1;
    else
        return 0;
}

int isfull2(int a[],int *top)
{
    if(*top==6)
        return 1;
    else
        return 0;
}

int isfull3(int a[],int *top)
{
    if(*top==9)
        return 1;
    else
        return 0;
}


int main()
{
    int top1,top2,top3,a[10]={0},t,x,y,z,n,i;

    printf("Here we are implementing 3 stack in one array\n");
    top1=-1;
    top2=2;
    top3=5;

    printf("How many operations you want in your array:");
    scanf("%d",&t);
    while(t--)
    {
        printf("\nEnter 1 if you want to push and 0 for pop\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("\nEnter the number you want to push and stack number followed by space:");
            scanf("%d %d",&x,&y);
            if(y==0)
            {
                if(isfull1(a,&top1))
                    printf("can't insert more elements in 1\n");
                else
                    push(a,x,&top1);
            }

            else if(y==1)
            {
                if(isfull2(a,&top2))
                    printf("can't insert more elements in 2\n");
                else
                    push(a,x,&top2);
            }
            else if(y==2)
            {
                if(isfull3(a,&top3))
                    printf("can't insert more elements in 3\n");
                else
                    push(a,x,&top3);
            }

        }
        else
        {
            printf("\nEnter the stack number you want to pop:");
            scanf("%d",&z);
            if(z==0)
            {
                if(isempty1(a,&top1))
                    printf("stack 1 is empty\n");
                else
                    pop(a,&top1);
            }
            else if(z==1)
            {
                if(isempty2(a,&top2))
                    printf("stack 2 is empty\n");
                else
                    pop(a,&top2);
            }
            else if(z==2)
            {
                if(isempty3(a,&top3))
                    printf("stack 3 is empty\n");
                else
                    pop(a,&top3);
            }
        }
        printf("\nstack 1:\n");
        for(i=0;i<=2;i++)
            printf("%d ",a[i]);
        printf("\n");
        printf("stack 2:\n");
        for(i=3;i<=5;i++)
            printf("%d ",a[i]);
        printf("\n");
        printf("stack 3:\n");
        for(i=6;i<=8;i++)
            printf("%d ",a[i]);
        printf("\n\n");
    }
}

