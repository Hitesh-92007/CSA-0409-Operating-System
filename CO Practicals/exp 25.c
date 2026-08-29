#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    struct stat st;
    DIR *d;
    struct dirent *e;

    fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    write(fd, "Hello UNIX", 10);

    lseek(fd, 0, SEEK_SET);
    printf("File offset: %ld\n", lseek(fd, 0, SEEK_CUR));

    fstat(fd, &st);
    printf("File size: %ld bytes\n", st.st_size);

    printf("Directory files:\n");
    d = opendir(".");
    while ((e = readdir(d)) != NULL)
        printf("%s\n", e->d_name);

    close(fd);
    closedir(d);
    return 0;
}
