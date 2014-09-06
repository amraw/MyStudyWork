#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

pid_t spaw(char *program,char **arg_list);

int main()
{
	char *arg_list[]={"ls","-l","/",NULL};
	spaw("ls",arg_list);
	fprintf(stdout,"The process is terminated\n");
	return 0;
	}

pid_t spaw(char *program,char **arg_list)
{
	pid_t childProcess;
	childProcess=fork();
	if(childProcess!=0)
	return childProcess;
	else
	{
		execvp(program,arg_list);
		fprintf(stderr,"Error in executing the program ls\n");
		abort();
		}
}
