#include <stdio.h>

int main() {
    int n, i, choice;

    printf("Enter number of philosophers: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("\nPhilosopher %d is thinking", i);
        printf("\nPhilosopher %d wants to eat", i);
        printf("\nPhilosopher %d is eating", i);
        printf("\nPhilosopher %d has finished eating\n", i);
    }

    return 0;
}
