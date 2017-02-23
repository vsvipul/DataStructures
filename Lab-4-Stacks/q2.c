#include<stdio.h>
int stno;
struct stack
{
     int dat[10];
     int top;
}s[3];


void push(int num,int stno)
{

    if(s[stno].top==4)
    {
        printf("stack Overflow");
    }
    else
    {

        s[stno].top++;
        s[stno].dat[s[stno].top]=num;

    }

}
int pop(int stno)
{
    int num;
    if(s[stno].top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        num=s[stno].dat[s[stno].top];
        s[stno].top--;
   }
   return num;

}
void display()
{
    int i;
    if(s[stno].top==-1)
    printf("stack is empty");
    else{
    for(i=s[stno].top;i>-1;i--)
    printf("%d ",s[stno].dat[i]);

    }

}
int peek(void)
{
    if(s[stno].top>0);
    return s[stno].dat[s[stno].top-1];
}
int main()
{   int wish,num;
    wish=1;
   while(wish!=0)
  {
   if(wish==1)
   {
       printf("enter the element and stk no to be pushed");
       scanf("%d%d",&num,&stno);
       push(num,stno);
       printf("push:1,pop:2,stop:0");
       scanf("%d",&wish);
   }
   if(wish==2)
   {
       printf("Enter stack number");
       scanf("%d",&stno);
       num=pop(stno);
       printf("%d\n",num);
       printf("push:1,pop:2,stop:0");
       scanf("%d",&wish);
   }
  }
}
