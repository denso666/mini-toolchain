#ifndef LIB_UNAME
#define LIB_UNAME

#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/**
 * @brief Print system information
 * @return On success, EXIT_SUCCESS is returned. On error, EXIT_FAILURE is returned.
 */
void __uname__(void);

#endif