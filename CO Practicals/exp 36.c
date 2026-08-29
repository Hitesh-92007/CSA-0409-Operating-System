#include <stdio.h>

int main() {
    int n, block[20], i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Linked allocation:\n");

    for (i = 0; i < n; i++) {
        printf("%d -> ", block[i]);
    }

    printf("NULL\n");
    printf("First block: %d\n", block[0]);
    printf("Last block: %d\n", block[n - 1]);

    return 0;
}
