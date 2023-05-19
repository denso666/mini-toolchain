#include "../include/commands.h"

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

void __lsmod__(void)
{
    int fd = open("/proc/modules", O_RDONLY);
    if (fd)
    {
        char* buf = (char*)malloc(1);
        while (read(fd, buf, 1))
        {
            fprintf(stdout, "%s", buf);
        }
        close(fd);
        free(buf);
        exit(0);
    }
    else
    {
        perror("lsmod");
        exit(1);
    }
}

void __mkdir__(const char* path)
{
    struct stat st;		
    if (stat(path, &st) == -1)
    {
        if (!mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))
        {
            fprintf(stdout, "mkdir: created directory '%s'\n", path);
            exit(0);
        }
        else perror("mkdir");
    }
    else fprintf(stderr, "mkdir: cannot create directory '%s': File or directory exists\n", path);
    exit(1);
}

void __kill__(const char* pid, const char* sig)
{
    fprintf(stderr, "kill: not implemented\n");
    exit(1);
}
