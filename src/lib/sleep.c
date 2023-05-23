#include "../include/sleep.h"

int valid_time_interval(const char* nptr)
{
    if (nptr != NULL)
    {
        int i = 0;
        int points = 0;
        while (nptr[i] != '\0')
        {
            // is a non valid numeric character
            if (nptr[i] == '.') points++;
            else if (nptr[i] < '0' || nptr[i] > '9') return 2;
            if (points > 1) return 2;
            i++;
        }
        return 0; // valid number
    }
    return 1; // null ptr provided
}

void __sleep__(const int intc, const char* intv[])
{
    int status;
    int invalid_intervals = 0;
    float total_interval = 0.0;
    for (int i=1; i<intc; i++)
    {
        // valid time intervals format
        status = valid_time_interval(intv[i]);
        if (status == 2)
        {
            fprintf(stderr, "sleep: invalid time interval '%s'\n", intv[i]);
            invalid_intervals = 1;
        }
        else total_interval += atof(intv[i]);
    }
    // invalid intervals provided, exit with failure
    if (invalid_intervals) exit(1);
    else
    {
        if (usleep(total_interval * 1000000) < 0)
        {
            // error on execution
            perror("sleep");
            exit(1);
        }
        else exit(0);
    }
}
