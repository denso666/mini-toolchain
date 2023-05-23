#ifndef LIB_KILL
#define LIB_KILL

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>

#define DEFAULT_SIG SIGTERM

/**
 * @brief Sends the specified signal to the specified processes.
 * @param c_pid process id
 * @param c_sig SIGNAL to send
 * @return delivery status
 */
void __kill__(const long pid, const int sig);

#endif
