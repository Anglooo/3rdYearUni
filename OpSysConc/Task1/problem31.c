#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

void main(int argc, char *argv[])
{
	execve("/bin/ls", argv, NULL);

	//return (int)1;

}