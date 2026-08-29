#include <stdio.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int n, i, pos;

    fp = fopen("employee.dat", "w+b");

    if (fp == NULL) {
        printf("File cannot be opened");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter ID, Name and Salary: ");
        scanf("%d %s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("Enter employee position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position");
        fclose(fp);
        return 0;
    }

    fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);
    fread(&e, sizeof(e), 1, fp);

    printf("\nID: %d", e.id);
    printf("\nName: %s", e.name);
    printf("\nSalary: %.2f", e.salary);

    fclose(fp);
    return 0;
}
