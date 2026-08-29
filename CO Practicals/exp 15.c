#include <stdio.h>

int main() {
    char dir[10][20], file[10][20];
    int n, i;

    printf("Enter number of users: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter user name: ");
        scanf("%s", dir[i]);

        printf("Enter file name: ");
        scanf("%s", file[i]);
    }

    printf("\nTwo Level Directory:\n");
    for(i = 0; i < n; i++)
        printf("%s -> %s\n", dir[i], file[i]);

    return 0;
}
