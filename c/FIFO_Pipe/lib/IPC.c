#include <unistd.h>
#include <fcntl.h>
#include "./ipc.h"
#include <stdio.h>

void
Wait()
{
    char buf[2];
    int fd = open("/tmp/SeGMsg", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }
    read(fd, buf, 1);
    close(fd);
}

void
Signal()
{
    char buf[2]="X";
    int fd = open("/tmp/SeGMsg", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return;
    }
    write(fd, buf, 1);
    close(fd);
}