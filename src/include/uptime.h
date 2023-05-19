#ifndef LIB_UPTIME
#define LIB_UPTIME

#include <sys/sysinfo.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Tell how long the system has been running
 * @return On sucees, EXIT_SUCCESS is returned. On error, EXIT_FAILURE is returned.
 */ 
void __uptime__(void);

#endif
