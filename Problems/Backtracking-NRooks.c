#include <stdio.h>
#include <string.h>

void printsolution(int n, int board[n][n])
{
	static int k=1;
	printf("%d - \n",k++);
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

int issafe(int n, int board[n][n], int row, int col)
{
	int i,j;
	for (i=0;i<col;i++)
	{
		if (board[row][i])
			return 0;
	}
	return 1;
}

int solvenqp(int n, int board[n][n], int col)
{
	int i;
	if (col>=n)
	{
		printsolution(n,board);
		return 1;
	}
	for (i=0;i<n;i++)
	{
		if (issafe(n,board,i,col))
		{
			board[i][col]=1;
			solvenqp(n,board,col+1);
			board[i][col]=0; //backtrack
		}
	}
	return 0;
}

void solvenq(int n)
{
	int board[n][n];
	memset(board,0,sizeof(board));
	if (solvenqp(n,board,0))
	{
		printf("Solution does not exist!\n");
		return;
	}
	return;
}

int main()
{
  int n;
  scanf("%d",&n);
  solvenq(n);
  return 0;
}
