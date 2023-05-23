#include "../include/mkdir.h"

void __mkdir__(const char* path)
{
    struct stat st;
	if (stat(path, &st) == -1)
    {
        if (!mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))
        {
            fprintf(stdout, "mkdir: created directory '%s'\n", path);
            exit(EXIT_SUCCESS);
        }
        else perror("mkdir");
    }
    else fprintf(stderr, "mkdir: cannot create directory '%s': File or directory exists\n", path);
    exit(EXIT_FAILURE);
}