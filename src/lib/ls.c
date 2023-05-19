#include "../include/ls.h"

void __ls__(const char* path)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d)
    {	
        fprintf(stdout, "%s:\n", path);
        while ((dir = readdir(d)) != NULL)
        {
            fprintf(stdout, "%s\n", dir->d_name);
        }
        closedir(d);
        fprintf(stdout, "\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        perror("ls");
        exit(EXIT_FAILURE);
    }
}