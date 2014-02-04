#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	pid_t p = fork();

	if(p == -1){
		exit(EXIT_FAILURE);
	}

	if(p == 0){
		execve("/bin/ls", argv, NULL);
		return(1);
	}
	int result;

	waitpid(p,&result,0);

	if(result == 0)
	{
		printf("Success\n");
	}
	else{
		printf("Error\n");
	}

}