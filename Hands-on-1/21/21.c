/*
============================================================================
Name : 21.c
Author : Siddharth V. Pillai
Description : Write a program, call fork and print the parent and child process id.
Date: 1st Sep, 2023.
============================================================================
*/


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
