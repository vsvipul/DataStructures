#include <stdio.h>
#include <string.h>

void printsolution(int n, int board[n][n])
{
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
	for (i=row,j=col; i>=0 && j>=0 ;i--,j--)
	{
		if (board[i][j])
			return 0;
	}
	for (i=row,j=col;j>=0 && i<n;i++,j--)
	{
		if (board[i][j])
			return 0;
	}
	return 1;
}

int solvenqp(int n, int board[n][n], int col)
{
	int i;
	if (col>=n)
		return 1;
	for (i=0;i<n;i++)
	{
		if (issafe(n,board,i,col))
		{
			board[i][col]=1;
			if (solvenqp(n,board,col+1))
				return 1;
			board[i][col]=0; //backtrack
		}
	}
	return 0;
}

void solvenq(int n)
{
	int board[n][n];
	memset(board,0,sizeof(board));
	if (!solvenqp(n,board,0))
	{
		printf("Solution does not exist!\n");
		return;
	}
	printsolution(n, board);
	return;
}

int main()
{
  int n;
  scanf("%d",&n);
  solvenq(n);
  return 0;
}
