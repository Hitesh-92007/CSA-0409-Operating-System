#include <stdio.h>

int main() {
    int index, n, i, block[20];

    printf("Enter index block: ");
    scanf("%d", &index);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Index Block: %d\n", index);
    printf("File blocks: ");
    for (i = 0; i < n; i++)
        printf("%d ", block[i]);

    printf("\n");
    return 0;
}
