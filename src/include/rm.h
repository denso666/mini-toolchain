#ifndef LIB_RM
#define LIB_RM

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * @brief Remove a file or directory
 * @param argc Arguments quantity
 * @param argv Arguments
 * @return On success, zero is returned. On error, EXIT_FAILURE is returned.
 */
void __rm__(const int, const char**);

#endif

/* Cases

 rm file
 rm fa fb fc
 rm -r target_dir

*/
