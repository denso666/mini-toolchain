#include "../include/uptime.h"

void __uptime__(void)
{
    struct sysinfo s_info;
    if (!sysinfo(&s_info))
    {
        long seconds = s_info.uptime;
        long hours = seconds/3600;
        seconds %= 3600;
        long minutes = seconds/60;
        seconds %= 60;
        fprintf(stdout, "up %ld hours, %ld minutes, %ld seconds\n", hours, minutes, seconds);
        exit(EXIT_SUCCESS);
    }
    else
    {
        perror("uptime");
        exit(EXIT_FAILURE);
    }
}