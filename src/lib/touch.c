#include "../include/touch.h"
#include <stdlib.h>

void __touch__(const char* path)
{
    struct stat st;
    // exist
    if (!stat(path, &st))
    {
        // is a directory
        if ((st.st_mode & S_IFMT) == S_IFDIR)
        {
            fprintf(stderr, "touch: %s: Is a directory\n", path);
            exit(EXIT_FAILURE);
        }
        // update last access and modify date
        else
        {
            struct utimbuf new_time;
            time_t t = time(NULL);
            new_time.actime = t;
            new_time.modtime = t;
            
            if (utime(path, &new_time) != 0)
            {
                fprintf(stderr, "touch: %s: %s\n", path, strerror(errno));
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }
    }
    // create file
    else
    {
        if (creat(path, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP) < 0)
        {
            perror("touch");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }    
}