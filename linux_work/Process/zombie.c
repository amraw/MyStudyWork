#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	pid_t childProcess;
	childProcess=fork();
	if(childProcess!=0)
	sleep(60);
	else
	exit(0);
	
	return 0;
	}
