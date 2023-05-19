#ifndef LIB_TOUCH
#define LIB_TOUCH

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <utime.h>
#include <time.h>

/**
 * @brief Change file timestamps
 * @param path target file
 * @return status of creation or status change
 */
void __touch__(const char*);

#endif
