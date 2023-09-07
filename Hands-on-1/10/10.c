/*
============================================================================
Name : 10.c
Author : Siddharth V. Pillai
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 18th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
	int fd = open("seek",O_CREAT|O_RDWR);
	char buf[200];
	read(0,buf,20);
	write(fd,buf,10);

	int l_seek = lseek(fd,10L,SEEK_CUR);
	
	write(fd,buf+10,10);

	printf("Return value of lseek: %d",l_seek);
	return 0;
}
