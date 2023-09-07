/*
============================================================================
Name : 16.c
Author : Siddharth V. Pillai
Description : Write a program to perform mandatory locking.
b. Implement read lock
Date: 25th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(void){
	int fd = open("file",O_RDWR);
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside Critical Section\n");
	getchar();
	printf("After critical section\n");
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	return 0;
}
