#include "./include/libs.h"

int main(int argc, char const *argv[])
{
    pid_t child_id;
    int status, group_status;
    const char* command = argv[0];

    // sleep 	-> OK
    if (!strcmp(command, "./sleep"))
    {
        // not enough arguments
        if (argc == 1)
        {
            printf("sleep: missing operan\n");
            exit(EXIT_FAILURE);
        }
        else __sleep__(argc, argv);
    }
    // uname 	-> OK
    else if (!strcmp(command, "./uname"))
    {
        // extra arguments
        if (argc > 1)
        {
            printf("uname: extra operand '%s'\n", argv[1]);
            printf("Usage: uname\n");
            exit(EXIT_FAILURE);
        }
        else __uname__();
    }
    // ls 		-> VERIFY
    else if (!strcmp(command, "./ls"))
    {
        if (argc == 1) __ls__("./");
        else
        {
            group_status = 0;
            for (int i=1; i<argc; i++)
            {
                if ((child_id = fork()) == 0) __ls__(argv[i]);
                else if (child_id < 0)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else 
                {
                    waitpid(child_id, &status, 0);
                    group_status = group_status || status;
                }
            }
            return group_status;
        }		
    }
    // cat		-> OK
    else if (!strcmp(command, "./cat"))
    {
        // not enough arguments
        if (argc == 1)
        {
            printf("cat: not provided file or directory\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            group_status = 0;
            for (int i=1; i<argc; i++)
            {
                if ((child_id = fork()) == 0) __cat__(argv[i]);
                else if (child_id < 0)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else 
                {
                    waitpid(child_id, &status, 0);
                    group_status = group_status || status;
                }
            }
            return group_status;
        }
    }
    // lsmod 	-> OK
    else if (!strcmp(command, "./lsmod"))
    {
        // extra arguments
        if (argc > 1)
        {
            printf("lsmod: extra operand '%s'\n", argv[2]);
            printf("Usage: lsmod\n");
            exit(EXIT_FAILURE);
        }
        else __lsmod__();
    }
    // uptime	-> OK
    else if (!strcmp(command, "./uptime"))
    {
        // extra arguments
        if (argc > 1)
        {
            printf("uptime: extra operand '%s'\n", argv[2]);
            printf("Usage: uptime\n");
            exit(EXIT_FAILURE);
        }
        else __uptime__();
    }
    // mkdir	-> OK
    else if (!strcmp(command, "./mkdir"))
    {
        // not enough arguments
        if (argc == 1)
        {
            printf("mkdir: missing operand\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            group_status = 0;
            for (int i = 1; i<argc; i++)
            {
                if ((child_id = fork()) == 0) __mkdir__(argv[i]);
                else if (child_id < 0)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else 
                {
                    waitpid(child_id, &status, 0);
                    group_status = group_status || status;
                }
            }
            return group_status;
        }
    }
    // chown	-> OK
    else if (!strcmp(command, "./chown"))
    {
        // not enough or extra arguments
        if (argc != 4)
        {
            printf("chown: missing or extra operand\n");
            printf("Usage: chown -path -group -user\n");
            exit(EXIT_FAILURE);
        }
        else __chown__(argv[1], argv[2], argv[3]);
    }
    // chmod 	-> NOT IMPLEMENTED
    else if (!strcmp(command, "./chmod"))
    {
        if (argc != 3)
        {
            printf("chmod: missing operand\n");
            printf("Usage: chmod -path -permissions\n");
            exit(EXIT_FAILURE);			
        }
        else __chmod__(argv[1], argv[2]);
    }
    // touch	-> OK
    else if (!strcmp(command, "./touch"))
    {
        if (argc != 2)
        {
            fprintf(stderr, "touch: missing operand\n");
            fprintf(stderr, "Usage: touch -path\n");
            exit(EXIT_FAILURE);
        }
        else __touch__(argv[1]);
    }
    // kill     -> NOT IMPLEMENTED
    else if (!strcmp(command, "./kill"))
    {
        if (argc < 2 || argc > 3)
        {
            fprintf(stderr, "kill: missing or extra operand\n");
            fprintf(stderr, "Usage: kill -pid [-sig, NULL to default signal 'TERM'])\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            char* endptr;
            errno = 0; /* Distinguish success/failure after 'strtol' call*/

            // verify pid integrity
            long pid = strtol(argv[1], endptr, 10);
            if (errno != 0 || endptr == argv[1])
            {
                fprintf(stderr, "kill: invalid pid\n");
                exit(EXIT_FAILURE);
            }

            // kill with DEFAULT signal
            if (argc == 2)
            {
                __kill__(pid, DEFAULT_SIG);
            }
            // kill with CUSTOM signal
            else
            {
                // verify signal integrity
                errno = 0;
                int sig = strtol(argv[2], endptr, 10);
                if (errno != 0 || endptr == argv[2])
                {
                    fprintf(stderr, "kill: invalid signal\n");
                    exit(EXIT_FAILURE);
                }
                __kill__(pid, sig);
            }
        }
    }
    // command not found
    else
    {
        printf("'%s' command not found\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return 0;
}
