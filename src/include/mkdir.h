#ifndef LIB_MKDIR
#define LIB_MKDIR

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/**
 * Create the Directory(ies), if they do not already exist
 * @param path target directory name 
 * @return null
 */
void __mkdir__(const char*);

#endif
