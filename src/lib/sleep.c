#include "../include/sleep.h"

void __sleep__(const int intc, const char* intv[])
{
    u_char invalid_intervals = 0x00;
    u_int total_interval = 0;
    for (int i=1; i<intc; i++)
    {
        if (valid_time_interval(intv[i]) == 2)
        {
            fprintf(stderr, "sleep: invalid time interval '%s'\n", intv[i]);
            invalid_intervals = 0x01;
        }
        else total_interval += (u_int)strtoul(intv[i], NULL, 10);
    }
    if (invalid_intervals) exit(EXIT_FAILURE);
    else
    {
        if (sleep(total_interval) < 0)
        {
            perror("sleep");
            exit(EXIT_FAILURE);
        }
        else exit(EXIT_SUCCESS);
    }
}
