/*
============================================================================
Name : 3.c
Author : Siddharth V. Pillai
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 11th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int f = creat("temp.txt", O_RDWR);
	printf("fd = %d",f);
	if(f<0){
		perror("Program");
		return 1;	
	}
}
