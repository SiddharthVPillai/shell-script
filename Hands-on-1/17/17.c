/*
============================================================================
Name : 17.c
Author : Siddharth V. Pillai
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 25th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int ticket;
	struct flock lock;
	int fd;
	fd = open("data",O_RDWR);
	read(fd,&ticket,sizeof(ticket));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before Critical Section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Current ticket number: %d\n",ticket);
	ticket++;
	lseek(fd,0L,SEEK_SET);
	write(fd,&ticket,sizeof(ticket));
	printf("Inside critical section\n");
	printf("Enter to unlock\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	return 0;
}
