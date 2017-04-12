/*Description 

After the quiz the students come outside the rooms and make a common queue. Every student has an indication of the marks scored. The students arrange themselves into k groups. The first group is of students who score between 0 (inclusive) to 100/k (exclusive), the second group of students who score between 100/k (inclusive) to 100/k*2 (exclusive), and so on till the last group who score between 100/k*(k-1) (inclusive) to 100 (inclusive). To make the group every student comes forward and connects to the group by adding as a node at the end of the linked list of the corresponding group. So there are k linked lists in all, one for every group. 

All the groups again merge to make one linked list. The first group to lead the linked list is the group that has the largest size, followed by the group that has the second largest size, and so on. So you need to take the largest linked list first. Then take the second largest linked list and join at the end of the largest linked list. Then take the next largest linked list and add it to the end of the merged linked list so far. In case of a tie, a lower marks group is preferred. Print the final linked list.

Input Format 

The first line is n and k, the total number of students and the number of groups. Then n lines follow from the head in the initial queue, each line mentioning the student roll number and expected marks in quiz.

Output Format 

n lines, each printing the roll number of the student in the linked list.

Constraints 

1 ≤ n, k ≤ 50
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char s[11];
	int marks;
	struct node *link;
};
typedef struct node NODE;

NODE *addatbeg(NODE *start, char str[], int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	strcpy(tmp->s,str);
	tmp->marks=data;
	tmp->link=start;
	start=tmp;
	return start;
}

NODE *addatend(NODE *start, char str[], int data)
{
	NODE *tmp;
	tmp=(NODE *)malloc(sizeof(NODE));
	strcpy(tmp->s,str);
	tmp->marks=data;
	NODE *p;
	p=start;
	while (p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}

int main()
{
	int n,k,mrks,i,j;
	char s[11];
	struct node* start=NULL;
	scanf("%d%d",&n,&k);
	scanf("%s%d",s,&mrks);
	start=addatbeg(start, s, mrks);
	n--;
	for (i=0;i<n;i++)
	{
		scanf("%s%d",s,&mrks);
		start=addatend(start, s, mrks);
	}
	int l,r=0;
	int temp=100/k;
	int counts[k+1];
	int c;
	for (j=1;j<=k;j++)
	{
		c=0;
		l=r;
		r=temp*j;
		struct node *tmp=start;
		while (tmp!=NULL)
		{
			if (j!=k)
			{
				if (tmp->marks>=l && tmp->marks<r)
					c++;
			}
			else
			{
				if (tmp->marks>=l && tmp->marks<=r)
					c++;
			}
			tmp=tmp->link;
		}
		counts[j]=c;
	}
	while (1)
	{
		int maxpos=-1,maxi=0;
		for (j=1;j<=k;j++)
		{
			if (counts[j]>maxi)
			{
				maxi=counts[j];
				maxpos=j;
			}
		}
		if (maxpos==-1)
			break;
		r=temp*maxpos;
		l=temp*(maxpos-1);
		struct node *tmp=start;
		while (tmp!=NULL)
		{
			if (maxpos!=k)
			{
				if (tmp->marks>=l && tmp->marks<r)
					printf("%s\n",tmp->s);
			}
			else
			{
				if (tmp->marks>=l && tmp->marks<=r)
					printf("%s\n",tmp->s);
			}
			tmp=tmp->link;
		}
		counts[maxpos]=0;
	}
	return 0;
}
