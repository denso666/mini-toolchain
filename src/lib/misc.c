#include "../include/misc.h"

int valid_time_interval(const char* nptr)
{
    if (nptr != NULL)
    {
        for (int i = 0; nptr[i] != '\0'; i++)
        {
            if (nptr[i] < '0' || nptr[i] > '9') return 1;
        }
        return 0;
    }
    return 1;
}
