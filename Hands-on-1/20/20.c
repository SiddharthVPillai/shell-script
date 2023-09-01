#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>

int main(){
	printf("Current Priority: %d\n",getpriority(PRIO_PROCESS,0));
	nice(-1);
	printf("Modified priority: %d\n",getpriority(PRIO_PROCESS,0));
	return 0;
}
