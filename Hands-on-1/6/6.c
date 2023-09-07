/*
============================================================================
Name : 6.c
Author : Siddharth V. Pillai
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 18th Aug, 2023.
============================================================================
*/


#include<unistd.h>
#include<string.h>
const int MAX_SIZE = 1024;

int main(){
	char buf[MAX_SIZE];
	
	read(0,buf,MAX_SIZE);
	write(1,buf,strlen(buf)+1);
	return 0;
}
