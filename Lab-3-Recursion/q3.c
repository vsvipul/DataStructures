//  Make a recursive function sum(X,i,j,k,l,n) that computes the sum of a 2-D array from the index [i][j] to the index [k][l], given that 0≤i≤k<n and 0≤j≤l<n.

#include <stdio.h>

int fnc(int n,int m,int arr[n][m],int a,int b,int c,int d, int sum)
{
    if (a<=c)
    {
    	if (b<m)
    	{
    		if (a!=c)
    		{
    			sum+=arr[a][b];
    			return fnc(n,m,arr,a,++b,c,d,sum);
    		}
    		else
    		{
    			if (b<=d)
    				sum+=arr[a][b];
    			return fnc(n,m,arr,a,++b,c,d,sum);
    		}
    	}
    	else
    	{
    		b=0;++a;
    		return fnc(n,m,arr,a,b,c,d,sum);
    	}
    }
    return sum;
}

int main()
{
	int i,a,b,c,d,j,n,m;
	scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
	int arr[n][m];
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
		scanf("%d",&arr[i][j]);
		}
	}
	int sum=0;
	int res=fnc(n,m,arr,a,b,c,d,sum);
	printf("%d\n",res);
	return 0;
}
