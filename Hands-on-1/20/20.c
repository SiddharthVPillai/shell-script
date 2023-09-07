/*
============================================================================
Name : 20.c
Author : Siddharth V. Pillai
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 1st Sep, 2023.
============================================================================
*/

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
