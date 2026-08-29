#include <stdio.h>

int main() {
    printf("Linux File Permissions:\n");
    printf("r = Read    (4)\n");
    printf("w = Write   (2)\n");
    printf("x = Execute (1)\n\n");

    printf("Types of Users:\n");
    printf("u = Owner\n");
    printf("g = Group\n");
    printf("o = Others\n\n");

    printf("Example: chmod 754 file.txt\n");
    printf("Owner : rwx\n");
    printf("Group : r-x\n");
    printf("Others: r--\n");

    return 0;
}
