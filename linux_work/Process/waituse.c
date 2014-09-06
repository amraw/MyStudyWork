#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
pid_t spaw(char *program,char **arg_list)
{
	pid_t childProcess;
	childProcess=fork();
	if(childProcess!=0)
	return childProcess;
	else
	{
		execvp(program,arg_list);
		fprintf(stderr,"Error occur while executing the ls program\n");
		abort();
		}
	}

int main()
{
	char *arg_list[]={"ls","-l","/",NULL};
	int childStatus;
	spaw("ls",arg_list);
	wait(&childStatus);
	if(WIFEXITED(childStatus))
	printf("Process executed Success fully with exit code %d\n",WEXITSTATUS(childStatus));
	else
	printf("The child process exited abnormally\n");
	return 0;
	}
