#include<stdio.h>
#include<stdlib.h>
#include<sched.h>

int main(){
	int sch;
	struct sched_param policy;
	if(sched_getparam(0,&policy)==-1){
		exit(EXIT_FAILURE);
	}
	if(sched_getscheduler(0)==-1){
		exit(EXIT_FAILURE);
	}

	printf("Current scheduling policy: %d\n",policy.sched_priority);
	policy.sched_priority = 20;

	if(sched_setscheduler(0,SCHED_FIFO,&policy)==-1)
			exit(EXIT_FAILURE);
	printf("New scheduling policy: %d\n",policy.sched_priority);
	return 0;
}
