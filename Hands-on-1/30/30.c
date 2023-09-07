/*
============================================================================
Name : 30.c
Author : Siddharth V. Pillai
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 5th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define PATH "/home/siddharth-pillai/Desktop/ubuntu/script/Hands-on-1/30/prog"

#define Hour 7
#define Minute 30
#define Second 0

void exe(){
	execl(PATH,PATH,(char*)0);
	perror("execl failure");
	exit(EXIT_FAILURE);
}

int main(){
	if(fork()){
		exit(EXIT_SUCCESS);
	}
	if(setsid()<0){
		perror("setsid failure");
		exit(EXIT_FAILURE);
	}

	if(chdir("/")<0){
		perror("chdir failed");
		exit(EXIT_FAILURE);
	}

	close(0);
	close(2);

	while(1){
		time_t cur;
		struct tm *info;
		time(&cur);
		info = localtime(&cur);

		if(info->tm_hour == Hour && info->tm_min==Minute && info->tm_sec==Second){
			exe();
		}
		sleep(1);
	}
	return 0;	
}
