#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

sig_atomic_t sigUser1Count=0;

void handler(int sigNumber)
{
	++sigUser1Count;
}

int main()
{
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler=&handler;
	sigaction(SIGUSR1,&sa,NULL);
	return 0;
}
