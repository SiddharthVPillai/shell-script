#include<stdio.h>
#include<unistd.h>

int main(){
	if(!fork()){
		printf("child id: %d\n",getpid());
		sleep(20);
	}
	else{
		sleep(1);
		printf("Parent terminating\n");	
	}
	return 0;
}
