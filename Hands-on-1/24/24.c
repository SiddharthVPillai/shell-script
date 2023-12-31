/*
============================================================================
Name : 24.c
Author : Siddharth V. Pillai
Description : Write a program to create an orphan process.
Date: 5th Sep, 2023.
============================================================================
*/

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
