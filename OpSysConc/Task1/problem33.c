#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	
	
	int pid;	
	pid = fork();
	char *test  = argv[0];
	
	if(pid == -1){
		exit(EXIT_FAILURE);
	}

	if(pid == 0)
	{
		int pipefd[2];
		if (pipe(pipefd)) {
			perror("pipe");
			exit(127);
		}
		 
		 switch (fork()) {
    case -1:
        perror("fork");
    case 0:
          
        close(pipefd[0]); 
        dup2(pipefd[1], 1);  
        close(pipefd[1]); 
        execvp("ls", argv);
        exit(126);
    default:
     
        close(pipefd[1]);  
        dup2(pipefd[0], 0);  
        close(pipefd[0]);  
        execvp(test, argv);
        exit(125);
    }
	}
	
return(0);	 
}