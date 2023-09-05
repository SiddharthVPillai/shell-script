#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
	pid_t id[3];
	for(int i=0;i<3;i++){
		id[i] = fork();
		if(id[i]<0){
			printf("FORK failed");
			exit(EXIT_FAILURE);
		}
		else if(id[i]==0){
			printf("Chid number: %d - id: %d\n",i+1,getpid());
			sleep(2);
			exit(EXIT_SUCCESS);
		}
	}
	int stat;
	pid_t c_id;

	c_id = waitpid(id[1],&stat,0);
	if(c_id==-1)
			exit(EXIT_FAILURE);
	if(WIFEXITED(stat))
			printf("Parent %d : child no 2  exited with status %d\n",c_id,WEXITSTATUS(stat));
	else
		printf("Abnormal termination\n");
	return 0;
}
