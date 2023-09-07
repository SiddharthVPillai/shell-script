/*
============================================================================
Name : 13.c
Author : Siddharth V. Pillai
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 19th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/select.h>
#include<unistd.h>
int main(){
	fd_set rfds;
	struct timeval tv;
	int retval;
	char buf[60];
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;
	retval = select(1,&rfds,NULL,NULL,&tv);
	read(0,buf,60);
	if(retval){
		printf("Data available within 10 sec\n");
		printf("%s",buf);
	}
	else
		printf("Data not available within 10 sec\n");
	return 0;
}
