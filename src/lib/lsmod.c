#include "../include/lsmod.h"

void __lsmod__(void)
{
    int fd = open("/proc/modules", O_RDONLY);
    if (fd)
    {
        char* buf = (char*)malloc(1);
        while (read(fd, buf, 1))
        {
            fprintf(stdout, "%s", buf);
        }
        close(fd);
        free(buf);
        exit(EXIT_SUCCESS);
    }
    else
    {
        perror("lsmod");
        exit(EXIT_FAILURE);
    }
}