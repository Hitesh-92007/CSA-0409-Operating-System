#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char data[50], buffer[50];

    printf("Enter data: ");
    scanf(" %[^\n]", data);

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    write(fd, data, sizeof(data));

    lseek(fd, 0, SEEK_SET);

    read(fd, buffer, sizeof(buffer));

    printf("File data: %s\n", buffer);

    close(fd);

    return 0;
}
