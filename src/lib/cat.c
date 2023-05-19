#include "../include/cat.h"
#include <stdlib.h>

int __cat__(const char* path)
{
    struct stat st;
    // exist?
    if (stat(path, &st) != -1)
    {
        // is a directory?
        if ((st.st_mode & S_IFMT) == S_IFDIR)
        {
            fprintf(stderr, "cat: %s: Is a directory\n", path);
            exit(EXIT_FAILURE);
        }
        else
        {
            int fd = open(path, O_RDONLY);
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
                fprintf(stderr, "cat: '%s' %s\n", path, strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        fprintf(stderr, "cat: '%s' %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
}