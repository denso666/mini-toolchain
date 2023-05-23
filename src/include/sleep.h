#ifndef LIB_SLEEP
#define LIB_SLEEP

#include <sys/wait.h>
#include <stdlib.h>
#include <float.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

/**
 * @brief Convert string to integer valid interval
 * @param nptr number pointer
 * @return On success, zero is returned. On null pointer provided, one is returned. On non valid interval, two is returned
 */
int valid_time_interval(const char*);


/**
 * @brief Delay for a specified amount of time
 * @param intc interval counter
 * @param intv interval values
 * @return null
 */
void __sleep__(const int, const char*[]);

#endif
