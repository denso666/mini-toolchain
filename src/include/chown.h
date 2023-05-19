#ifndef LIB_CHOWN
#define LIB_CHOWN

#include <sys/sysinfo.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

/**
 * @brief Change the owner and group of a file
 * @param path target file or directory 
 * @param group group name
 * @param user user name
 * @return null
 */
void __chown__(const char*, const char*, const char*);

#endif
