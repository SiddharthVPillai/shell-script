/*
============================================================================
Name : 11.c
Author : Siddharth V. Pillai
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 19th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
	int fd1 = open("file.txt",O_RDWR);
	int fd2 = dup(fd1);
	if(fd1==-1 || fd2==-1){
		printf("Failed to open file\n");
		return -1;
	}	
	write(fd1,"Written with fd\n",16);
	write(fd2,"Written with dup() fd\n",22);
	printf("fd1-%d, fd2-%d ",fd1,fd2);
	
	int fd3 = dup2(fd1,6); 
	int fd4 = fcntl(fd1, F_DUPFD);
	if(fd3==-1 || fd4==-1){
		printf("Error creating copy\n");
		return -1;
	}
	write(fd3,"Written with dup2() fd\n",23);
	write(fd4,"Written with fcntl() fd\n",24);
	printf("fd3-%d, fd4-%d ",fd3,fd4);
	getchar();
	return 0;
}
