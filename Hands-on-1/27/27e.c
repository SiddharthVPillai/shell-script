/*
============================================================================
Name : 27e.c
Author : Siddharth V. Pillai
Description : Write a program to execute ls -Rl by the following system calls
e. execvp
Date: 1st Sep, 2023.
============================================================================
*/

#include<unistd.h>

int main(){
	char *ar[] = {"ls","-R","-l",NULL};
	execvp("ls",ar);
	return 0;
}
