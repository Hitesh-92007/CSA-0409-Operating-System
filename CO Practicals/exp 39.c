#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[20], n, head, size, i, j, temp, total=0;

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf("Enter initial head: ");
    scanf("%d",&head);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j]) {
                temp=a[i]; a[i]=a[j]; a[j]=temp;
            }

    printf("Order: ");

    for(i=0;i<n;i++)
        if(a[i]>=head) {
            total += abs(head-a[i]);
            head=a[i];
            printf("%d ",a[i]);
        }

    total += abs(head-(size-1));
    total += size-1;
    head=0;

    for(i=0;i<n;i++)
        if(a[i]<head || a[i]>=0) {
            if(a[i] < head) {
                total += abs(head-a[i]);
                head=a[i];
                printf("%d ",a[i]);
            }
        }

    printf("\nTotal head movement = %d\n",total);
    return 0;
}
