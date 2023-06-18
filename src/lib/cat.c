#include "../include/cat.h"

int __cat__(const char* path)
{
    struct stat st;
    // exist?
    if (stat(path, &st) != -1)
    {
        // is a directory?
        if ((st.st_mode & S_IFMT) == S_IFDIR)
        {
            errno = EISDIR;
            goto error;
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
            else goto error;
        }
    }
    else goto error;

error:
    perror("cat");
    exit(EXIT_FAILURE);
}