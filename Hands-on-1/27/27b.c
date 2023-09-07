/*
============================================================================
Name : 27b.c
Author : Siddharth V. Pillai
Description : Write a program to execute ls -Rl by the following system calls
b. execlp
Date: 1st Sep, 2023.
============================================================================
*/

#include<unistd.h>

int main(){
	execlp("ls","ls","-R","-l",NULL);
	return 0;
}
