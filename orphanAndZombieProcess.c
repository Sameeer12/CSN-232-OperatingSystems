#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){

	pid_t pid  = fork(); // forking child process

	if (!pid)
	{       // In child process
		printf("Orphan's PID is: %d  ",getpid()); // printing PID od child process 
                sleep(1); /* sleeping the child so that parent process can finish
	                     it's execution before completion iof child process */
		printf("New Parent PID of this child is: %d\n", getppid());  // printing the new parents PID
		                                                                
	
        pid = fork();  // forking a new child process in the child process i.e a grandchild is forked
		if (!pid)
		{  // in granchild process
			printf("Zombie's PID is: %d  ",getpid()); // printing PID od grandchild process which we want to make zombie
		}
		else
		{  //In child process
			sleep(10); // making child process sleep so that it can't recieve signal from grandchild about it's exit
		}
	}	

	else
	{ // In parent process
		printf("Parent's PID is: %d\n",getpid()); // printing PID of patrent 
    }

}