#include <stdio.h>

int main()
{
    int block[20],process[20],alloc[20];
    int m,n;

    printf("Enter number of blocks: ");
    scanf("%d",&m);

    printf("Enter block sizes:\n");
    for(int i=0;i<m;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter process sizes:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&process[i]);

    for(int i=0;i<n;i++)
        alloc[i]=-1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                alloc[i]=j;
                block[j]-=process[i];
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t",i+1,process[i]);

        if(alloc[i]!=-1)
            printf("%d\n",alloc[i]+1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
