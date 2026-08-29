#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[50];

    fp = fopen("file.txt", "w");
    fprintf(fp, "Hello File");
    fclose(fp);
    printf("File created and written.\n");

    fp = fopen("file.txt", "r");
    fgets(data, 50, fp);
    printf("File content: %s\n", data);
    fclose(fp);

    fp = fopen("file.txt", "a");
    fprintf(fp, " Management");
    fclose(fp);
    printf("Data appended.\n");

    remove("file.txt");
    printf("File deleted.\n");

    return 0;
}
