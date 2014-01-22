

#include <stdio.h>
#include <time.h>
#include <unistd.h>

 
int main(void)
{
	
	while(1==1)
	{
		time_t current_time;
		char* c_time_string;
		current_time = time(NULL);
		c_time_string = ctime(&current_time);
		(void) printf("Current time is %s", c_time_string);
		
		FILE *file; 
		file = fopen("/tmp/lablog.txt","a+"); 
		
		if (file != NULL)
		{
			fprintf(file,"%s",c_time_string); 
			fclose(file);
		}
		sleep(10);
	}
	
}
