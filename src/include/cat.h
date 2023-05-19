#ifndef LIB_CAT
#define LIB_CAT

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

/**
 * @brief Concatenate files and print on the standard output
 * @param path target file path
 * @return On success, content of file specified. On error, EXIT_FAILURE is returned.
 */
int __cat__(const char*);

#endif
