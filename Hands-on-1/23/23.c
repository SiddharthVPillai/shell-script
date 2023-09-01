#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		printf("child pid: %d\n",getpid());
	}	
	else if(pid>0){
		printf("Parent process\n");
	}
	else{
		printf("failed to create child");
	}
	getchar();
	return 0;
}
