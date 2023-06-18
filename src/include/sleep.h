#ifndef LIB_SLEEP
#define LIB_SLEEP

#include <unistd.h>
#include <errno.h>
#include "./misc.h"

/**
 * @brief Delay for a specified amount of time
 * @param intc interval counter
 * @param intv interval values
 * @return null
 */
void __sleep__(const int, const char*[]);

#endif
