#include "../include/chown.h"

void __chown__(const char* path, const char* group, const char* user)
{
    struct passwd* pwd;
    struct group* grp;
    struct stat st;

    // valid file
    if (stat(path, &st) == -1)
    {
        perror("chown");
        exit(1);
    }
    // group
    grp = getgrnam(group);
    if (!grp)
    {
        if (errno != 0) perror("chown");
        else fprintf( stderr, "chown: the given name or gid was not found\n");
        exit(1);
    }
    // user
    pwd = getpwnam(user);
    if (!pwd)
    {
        if (errno != 0) perror("chown");
        else fprintf( stderr, "chown: the given name or uid was not found\n");
        exit(1);
    }
    if (chown(path, pwd->pw_uid, grp->gr_gid))
    {
        perror("chown");
        exit(1);
    }
    exit(0);
}
