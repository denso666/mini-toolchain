#ifndef COMMANDS_H
#define COMMANDS_H

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <float.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <utime.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

/**
 * @brief Convert string to integer valid interval
 * @param nptr number pointer
 * @return On success, zero is returned. On null pointer provided, one is returned. On non valid interval, two is returned
 */
int valid_time_interval(const char*);


/**
 * Delay for a specified amount of time
 * @param intc interval counter
 * @param intv interval values
 * @return null
 */
void __sleep__(const int, const char*[]);

/**
 * Show the status of modules in the Linux Kernel
 * @return null
 */ 
void __lsmod__(void);

/**
 * Create the Directory(ies), if they do not already exist
 * @param path target directory name 
 * @return null
 */
void __mkdir__(const char*);

/**
 * @brief
 * @param pid process id
 * @param sig SIG to send
 * @return delivery status
 */
void __kill__(const char*, const char*);

#endif
