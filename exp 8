#include <stdio.h>

int main() {
    int n, tq, i;
    int bt[20], rem[20], wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++) {
        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d",&bt[i]);
        rem[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int time=0, done;

    while(1) {
        done=1;

        for(i=0;i<n;i++) {
            if(rem[i]>0) {
                done=0;

                if(rem[i]>tq) {
                    time += tq;
                    rem[i] -= tq;
                }
                else {
                    time += rem[i];
                    wt[i]=time-bt[i];
                    rem[i]=0;
                }
            }
        }

        if(done==1)
            break;
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    float avgwt=0,avgtat=0;

    for(i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];

        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    return 0;
}
