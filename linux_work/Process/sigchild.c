#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>


sig_atomic_t childStatus=0;

void cleanChildProcess(int signalNumber)
{
	int status;
	wait(&status);
	childStatus=status;
}

int main()
{
	struct sigaction sa;
	pid_t childProcess;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler=&cleanChildProcess;
	sigaction(SIGCHLD,&sa,NULL);
	childProcess=fork();
	if(childProcess!=0)
	{
	sleep(60);
    }
	else
	{
		exit(0);
	}
	
	return 0;
}
