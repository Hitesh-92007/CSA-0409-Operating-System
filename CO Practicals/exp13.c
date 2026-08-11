#include <stdio.h>

void firstFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    int b[m];

    for(int i=0;i<m;i++)
        b[i]=block[i];

    for(int i=0;i<n;i++)
        alloc[i]=-1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[j]>=process[i])
            {
                alloc[i]=j;
                b[j]-=process[i];
                break;
            }
        }
    }

    printf("\nFirst Fit\n");
    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,process[i]);
        if(alloc[i]!=-1)
            printf("%d\n",alloc[i]+1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    int b[m];

    for(int i=0;i<m;i++)
        b[i]=block[i];

    for(int i=0;i<n;i++)
        alloc[i]=-1;

    for(int i=0;i<n;i++)
    {
        int best=-1;

        for(int j=0;j<m;j++)
        {
            if(b[j]>=process[i])
            {
                if(best==-1 || b[j]<b[best])
                    best=j;
            }
        }

        if(best!=-1)
        {
            alloc[i]=best;
            b[best]-=process[i];
        }
    }

    printf("\nBest Fit\n");
    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,process[i]);
        if(alloc[i]!=-1)
            printf("%d\n",alloc[i]+1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    int b[m];

    for(int i=0;i<m;i++)
        b[i]=block[i];

    for(int i=0;i<n;i++)
        alloc[i]=-1;

    for(int i=0;i<n;i++)
    {
        int worst=-1;

        for(int j=0;j<m;j++)
        {
            if(b[j]>=process[i])
            {
                if(worst==-1 || b[j]>b[worst])
                    worst=j;
            }
        }

        if(worst!=-1)
        {
            alloc[i]=worst;
            b[worst]-=process[i];
        }
    }

    printf("\nWorst Fit\n");
    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,process[i]);
        if(alloc[i]!=-1)
            printf("%d\n",alloc[i]+1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int m,n;

    printf("Enter number of memory blocks: ");
    scanf("%d",&m);

    int block[m];

    printf("Enter block sizes:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int process[n];

    printf("Enter process sizes:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&process[i]);

    firstFit(block,m,process,n);
    bestFit(block,m,process,n);
    worstFit(block,m,process,n);

    return 0;
}
