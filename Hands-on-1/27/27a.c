/*
============================================================================
Name : 27a.c
Author : Siddharth V. Pillai
Description : Write a program to execute ls -Rl by the following system calls
a. execl
Date: 1st Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	execl("/usr/bin/ls","ls","-R","-l",(char*)0);
	return 0;
}
