/*
============================================================================
Name : 25.c
Author : Siddharth V. Pillai
Description : Write a program to create three child processes. The parent shouldwait for a particular child (use waitpid system call).
Date: 5th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	pid_t c1,c2,c3;
	c1 = fork();
	if(c1==0){
		printf("Child 1 id: %d\n",getpid());
		sleep(2);
	}
	else{
		c2 = fork();
		if(c2==0){
			printf("Child 2 id:%d\n",getpid());
			sleep(2);
		}
		else{
			c3 = fork();
			if(c3==0){
				printf("Child 3 id:%d\n",getpid());
				sleep(2);
			}
			else{
				int status;
				pid_t id;
				id = waitpid(c2,&status,0);
				if(id==-1){
					exit(EXIT_FAILURE);
				}
				if(WIFEXITED(status)){
					printf("Parent and child 2 exited with status %d",WEXITSTATUS(status));
				}
				else{
					printf("Abnormal termination\n");
				}
			}
		}
	}
	return 0;
}
