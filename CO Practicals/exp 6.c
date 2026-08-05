#include <stdio.h>

int main()
{
    int n,i,time=0,completed=0;
    int bt[20],rt[20],pr[20];
    int wt[20],tat[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority of P%d: ",i+1);
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    while(completed<n)
    {
        int highest=-1;
        int bestPriority=9999;

        for(i=0;i<n;i++)
        {
            if(rt[i]>0 && pr[i]<bestPriority)
            {
                bestPriority=pr[i];
                highest=i;
            }
        }

        if(highest==-1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0)
        {
            completed++;
            tat[highest]=time;
            wt[highest]=tat[highest]-bt[highest];
        }
    }

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t\t%d\t%d\t%d\n",
        i+1,pr[i],bt[i],wt[i],tat[i]);
    }

    return 0;
}
