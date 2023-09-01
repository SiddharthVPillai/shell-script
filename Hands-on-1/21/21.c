#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	if(!fork()){
		printf("Child process id: %d\n",getpid());
	}
	else{
		printf("Parent process id: %d\n",getpid());
	}
	wait(0);
	return 0;

}
