#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main()
{
	pid_t parent,child;
	parent=getppid();
	child=getpid();
	printf("The parent process id is %d\n",(int)parent);
	printf("The process id is %d\n",(int)child);
	return 0;
	}
