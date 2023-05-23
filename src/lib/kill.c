#include "../include/kill.h"

void __kill__(const long pid, const int sig)
{

	// check validity of pid
 	if (kill(pid, 0) == -1)
	{
		perror("kill");
		exit(EXIT_FAILURE);
	}

	// send signal
	if (kill(pid, sig) == -1)
	{
		perror("kill");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}