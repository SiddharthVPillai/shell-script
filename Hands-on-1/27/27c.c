/*
============================================================================
Name : 27c.c
Author : Siddharth V. Pillai
Description : Write a program to execute ls -Rl by the following system calls
c. execle
Date: 1st Sep, 2023.
============================================================================
*/

#include<unistd.h>

int main(){
	execle("/usr/bin/ls","-R","-l",NULL,NULL);
	return 0;
}
