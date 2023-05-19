#include "../include/chmod.h"
#include <stdlib.h>

int onlyOctal(const char* optr)
{
    if (optr != NULL)
    {
        int i = 0;
        while (optr[i] != '\0')
        {
            if (optr[i] < '0' || optr[i] > '7') return 2; // invalid character provided
            i++;
        }
        return 0; // valid octal number
    }
    return 1; // null provided 
}

void __chmod__(const char* path, const char* permissions)
{
    struct stat st;

    if (stat(path, &st) != 0)
    {
        fprintf(stderr, "chmod: %s: %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        if (strlen(permissions) == 3 && !onlyOctal(permissions))
        {
            int p = strtol(permissions, 0, 8);
            if (chmod(path, p) != 0)
            {
                perror("chmod");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }
        else
        {
            fprintf(stderr, "chmod: %s: invalid string permissions\n", permissions);
            exit(EXIT_FAILURE);
        }
    }
}