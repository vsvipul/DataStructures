/* Description 

A quiz is underway. Before the quiz n students queue up outside CC-3 and enter one by one. On entering CC-3 they are informed about the room number at which they need to enter, and they go and queue up outside the room, waiting for the room to be opened at the start time of the quiz. There are a total of t rooms numbered 0, 1, 2, 3 and so on till t-1. The rooms are opened one by one in increasing order of room number starting from room number 0 and the students enter. Print the order in which the students enter the room. It is necessary to use queues for this question.

Input Format 

The first line is n and t, the number of students and the number of rooms. Then n lines follow stating the roll number and room number of the students in the same order as they are present in the queue outside CC-III.

Output Format 

n lines stating the roll number of students in the order they enter the rooms.

Constraints 

1 ≤ n, t ≤ 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char q[12][105];
	int front;
	int rear;
};

void push(struct node *que, char s[])
{
	(que->rear)++;
	strcpy(que->q[que->rear],s);
}

void pop(struct node *que)
{
	(que->front)++;
}

int isempty(struct node *que)
{
	if((que->rear)<(que->front))
        return -1;
    return 1;
}

int main()
{
	int n,t,i,x;
	scanf("%d%d",&n,&t);
	struct node que[t];
	for (i=0;i<t;i++)
	{
		que[i].front=0;
		que[i].rear=-1;
	}
	char s[12];
	for (i=0;i<n;i++)
	{
		scanf("%s%d",s,&x);
		push(&que[x],s);
	}
	for (i=0;i<t;i++)
	{
		while(isempty(&que[i]) != -1)
		{
			printf("%s\n",(que[i].q[que[i].front]));
			pop(&que[i]);
		}
	}
	return 0;
}
