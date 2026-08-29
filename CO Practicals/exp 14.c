#include <stdio.h>
#include <string.h>

int main() {
    char files[20][20];
    int n, i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");
    for(i = 0; i < n; i++)
        scanf("%s", files[i]);

    printf("\nFiles in Single Level Directory:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", files[i]);

    return 0;
}
