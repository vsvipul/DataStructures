#include <stdio.h>
#include <stdlib.h>

struct edge
{
    struct vertex* destvertex;
    struct edge* nextedge;
};

struct vertex
{
    int info;
    struct vertex* nextvertex;
    struct edge* firstedge;
};

struct vertex* insertvertex(struct vertex* start, int u)
{
    struct vertex *tmp,*p;
    tmp=malloc(sizeof(struct vertex));
    tmp->info=u;
    tmp->nextvertex=NULL;
    tmp->firstedge=NULL;
    if (start==NULL)
    {
        start=tmp;
        return start;
    }
    p=start;
    while (p->nextvertex!=NULL)
        p=p->nextvertex;
    p->nextvertex=tmp;
    return start;
}

struct vertex* findvertex(struct vertex* start, int u)
{
    struct vertex *p, *loc;
    p=start;
    while (p!=NULL)
    {
        if (p->info==u)
        {
            loc=p;
            return loc;
        }
        p=p->nextvertex;
    }
    loc=NULL;
    return loc;
}

struct vertex* insertedge(struct vertex* start, int u, int v)
{
    struct vertex *locu,*locv;
    struct edge *tmp,*p;
    locu=findvertex(start, u);
    locv=findvertex(start, v);
    if (locu==NULL || locv==NULL)
    {
        return start;
    }
    tmp=malloc(sizeof(struct edge));
    tmp->destvertex=locv;
    tmp->nextedge=NULL;
    if (locu->firstedge==NULL) //first edge in that vertex
    {
        locu->firstedge=tmp;
        return start;
    }
    p=locu->firstedge;
    while (p->nextedge!=NULL)
        p=p->nextedge;
    p->nextedge=tmp;
    return start;
}

void display(struct vertex* start)
{
    struct vertex *p;
    struct edge *q;
    p=start;
    while (p!=NULL)
    {
        printf("%d ",p->info);
        q=p->firstedge;
        while (q!=NULL)
        {
            printf(" %d",q->destvertex->info);
            q=q->nextedge;
        }
        printf("\n");
        p=p->nextvertex;
    }
}

int checkedge(struct vertex* start, int u, int v)
{
    struct vertex *locu,*locv;
    struct edge *tmp,*p;
    locu=findvertex(start, u);
    locv=findvertex(start, v);
    if (locu->firstedge->destvertex==locv)
        return 1;
    tmp=locu->firstedge;
    while (tmp!=NULL)
    {
        if (tmp->destvertex==locv)
            return 1;
        tmp=tmp->nextedge;
    }
    return 0;
}

int main()
{
    struct vertex* start=NULL;
    int n,i,tmp;
    scanf("%d",&n);
    int arr[n+1];
    for (i=0;i<=n;i++)
    {
        scanf("%d",&tmp);
        arr[i]=tmp;
        start=insertvertex(start,tmp);
    }
    for (i=0;i<=n;i++)
    {
        if (i-2>=0)
            start=insertedge(start,arr[i],arr[i-2]);
        if (i+1<=n)
            start=insertedge(start,arr[i],arr[i+1]);
        if (i+2<=n)
            start=insertedge(start,arr[i],arr[i+2]);
        if (i+5<=n)
            start=insertedge(start,arr[i],arr[i+5]);
        if (i+10<=n)
            start=insertedge(start,arr[i],arr[i+10]);
    }
    display(start);
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
        if (checkedge(start,arr[org],arr[dest]))
            printf("Edge exists\n");
        else
            printf("Edge does not exist\n");
    }
    return 0;
}
