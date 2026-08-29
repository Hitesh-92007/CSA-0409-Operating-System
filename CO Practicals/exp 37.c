#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, a[20], i, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        total += abs(head - a[i]);
        head = a[i];
    }

    printf("Total head movement = %d\n", total);
    return 0;
}
