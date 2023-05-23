#ifndef LIB_LSMOD
#define LIB_LSMOD

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

/**
 * @brief Show the status of modules in the Linux Kernel
 * @return null
 */
void __lsmod__(void);

#endif
