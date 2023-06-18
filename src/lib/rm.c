#include "../include/rm.h"

void __rm__(const int argc, const char* argv[])
{
	// file deletion
	if (argc == 1)
	{
		if (unlink(argv[0]) == -1) goto error;
	}
	else
	{
		// directory deletion
		if (!strcmp(argv[0], "-r"))
		{
			if (remove(argv[1]) == -1) goto error;
		}
		else
		{
			errno = EINVAL;
			goto error;
		}
	}
	exit(EXIT_SUCCESS);

error:
	perror("rm");
	exit(EXIT_FAILURE);
}