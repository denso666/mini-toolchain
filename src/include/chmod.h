#ifndef LIB_CHMOD
#define LIB_CHMOD

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/**
 * @brief Verify valid octal string
 * @param optr octal pointer
 * @return On success, zero is returned. On null pointer provided, one is returned. On non valid character, two is returned.
 */
int onlyOcta(const char*);

/**
 * @brief Change file mode bits
 * @param path target file or directory
 * @param permissions string with new permissions (octal values)
 * @return null
 */
void __chmod__(const char*, const char*);

#endif
