/*
============================================================================
Name : 22.c
Author : Siddharth V. Pillai
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 1st Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
int main(){
	int fd = open("file.txt",O_RDWR);
       	if(!fork()){
		write(fd,"hello from child\n",17);
	}	
	else{
		write(fd,"hello from parent\n",18);
		wait(0);
		close(fd);
		fd = open("file.txt",O_RDONLY);
		char buf[50];
		read(fd,buf,sizeof(buf));
		printf("File content: \n%s",buf);
	}
	return 0;
}
