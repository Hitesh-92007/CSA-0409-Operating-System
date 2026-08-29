#include <stdio.h>

int main() {
    int start, n, i;

    printf("Enter starting block and number of blocks: ");
    scanf("%d%d", &start, &n);

    printf("Allocated blocks: ");
    for (i = 0; i < n; i++)
        printf("%d ", start + i);

    printf("\n");
    return 0;
}
