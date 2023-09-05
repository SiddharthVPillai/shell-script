#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		printf("child pid: %d\n",getpid());
		exit(0);
	}	
	else if(pid>0){
		printf("Parent process\n");
		sleep(10);
	}
	else{
		printf("failed to create child");
	}
	getchar();
	return 0;
}
