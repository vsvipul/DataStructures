#include<stdio.h>
int max=0;
struct stack
{
     int dat[5];
     int top;
}s;


void push(int num)
{

    if(s.top==4)
    {
        printf("stack Overflow");
    }
    else
    {

        s.top++;
        s.dat[s.top]=num;

    }

}
int pop()
{
    int num;
    if(s.top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        num=s.dat[s.top];
        s.top--;
   }
   return num;

}
void display()
{
    int i;
    if(s.top==-1)
    printf("stack is empty");
    else{
    for(i=s.top;i>-1;i--)
    printf("%d ",s.dat[i]);

    }

}
int peek(void)
{
    if(s.top>0);
    return s.dat[s.top-1];
}
int main()
{
    int k,sum=0,num;
    s.top=-1;
    for(k=0;k<5;k++)
    {
        printf("enter the element to be pushed");
        scanf("%d",&num);
        push(num);
    }
    sum=s.dat[0];
    s.top=-1;
     push(sum);
    for(k=1;k<5;k++)
    {
        if(sum<0)
        {
            sum=s.dat[k];
            push(sum);
        }
        else
        {
            sum=sum+s.dat[k];
            push(sum);
        }

    }
    display();


    return 0;
}
