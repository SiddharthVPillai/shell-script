/*
============================================================================
Name : 27d.c
Author : Siddharth V. Pillai
Description : Write a program to execute ls -Rl by the following system calls
d. execv
Date: 1st Sep, 2023.
============================================================================
*/

#include<unistd.h>

int main(){
	char * ar[] = {"ls","-R","-l",(char*)0};
	execv("/usr/bin/ls",ar);
	return 0;
}
