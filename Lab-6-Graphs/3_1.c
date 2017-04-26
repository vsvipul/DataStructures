#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,j,x;
    scanf("%d",&n);
    int arr[n+1][n+1];
    int inp[n+1];
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=n;j++)
        {
            arr[i][j]=0;
        }
    }
    for (i=0;i<=n;i++)
    {
        scanf("%d",&inp[i]);
    }
    for (i=0;i<=n;i++)
    {
        if (i-2>=0)
            arr[i][i-2]=1;
        if (i+1<=n)
            arr[i][i+1]=1;
        if (i+2<=n)
            arr[i][i+2]=1;
        if (i+5>=n)
            arr[i][i+5]=1;
        if (i+10<=n)
            arr[i][i+10]=1;

    }
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int org,dest;
    while (1)
    {
        printf("\nEnter origin and dest indices to check if edge exists. Enter (-1,-1) to exit.\n");
        scanf("%d%d",&org,&dest);
        if (org==-1 && dest==-1)
            break;
        if (org>n || dest>n || org<0 || dest<0)
        {
            printf("Please check indices entered.\n");
            continue;
        }
        if (arr[org][dest]==1)
            printf("Edge exists\n");
        else
            printf("Edge does not exist\n");
    }
    return 0;
}
