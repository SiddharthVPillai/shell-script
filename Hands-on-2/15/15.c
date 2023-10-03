/*
============================================================================    Name : 15.c
Author : Siddharth V. Pillai
Description : Write a simple program to send some data from parent to the child process.
Date: 3rd Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
int main(){
	int fd[2];
	pipe(fd);
	if(fork()){
		close(fd[0]);
		char buff[200];
		printf("\nEnter message to child: ");
		scanf("%[^\n]",buff);
		write(fd[1],buff, sizeof(buff));
	}
	else{
		close(fd[1]);
		char msg[200];
		read(fd[0],msg,sizeof(msg));
		printf("\nMessage from parent: %s",msg);
	}
	return 0;
}
