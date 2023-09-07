/*
============================================================================
Name : 1.c
Author : Siddharth V. Pillai
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 11th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int sl = symlink("tempfile","tempSL");
	if(sl<0){
		perror("Failed");
		return 1;
	}

	int hl = link("tempfile","tempHL");
	if(hl<0){
		perror("Failed");
		return 1;
	}

	int e = mknod("tempFIFO",S_IFIFO|0666,0);
	if(e<0)	perror("Failed");
	return 0;
}
