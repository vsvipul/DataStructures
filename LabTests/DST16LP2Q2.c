/*
Description 

The quiz starts. The quiz is of 100 marks. The passing marks are 40. There are n questions. Even though the questions are of different marks depending upon the difficulty, you can attempt exactly k questions due to time constraints. Find the total number of ways to attempt k questions such that you at least get the passing marks, assuming that an attempted question gives you full marks.

Input Format 

The first line contains t, the number of test cases. For every test case the next line is n and k, the total number of questions and the number of questions that you can attempt. Then n lines follow giving the total marks for a particular question.

Output Format 

For every test case, the number of ways you can attempt the question paper.

Constraints 

1 ≤ t ≤ 10
1 ≤ k ≤ n ≤ 15
*/

#include <stdio.h>

void solve(int arr[], int n, int k, int count, int sum, int i, int *ans)
{
	int j;
	if (sum>=40 && count==k)
	{
		*ans=*ans+1;
		return;
	}
	else
	{
		for (j=i+1;j<n;j++)
		{
			count++;sum+=arr[j];
			solve(arr,n,k,count,sum,j,ans); 
			count--;sum-=arr[j]; //backtrack
		}
	}
	return;
}

int main(){
	int t,n,k,i;
	int ans;
	scanf("%d",&t);
	while (t--)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		int arr[n];
		for (i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for (i=0;i<n;i++)
			solve(arr,n,k,1,arr[i],i,&ans);
		printf("%d\n",ans);
	}
	return 0;
}
