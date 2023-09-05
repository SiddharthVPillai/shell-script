#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	if(!fork()){
		printf("child pid: %d\n",getpid());
		exit(0);
	}	
	else {
		printf("Parent process\n");
		sleep(10);
	}

	getchar();
	return 0;
}
