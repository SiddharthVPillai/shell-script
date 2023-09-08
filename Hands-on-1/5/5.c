/*
============================================================================
Name : 5.c
Author : Siddharth V. Pillai
Description : Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 11th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>

int main(){
	int f1 = creat("temp1.txt",O_RDONLY);
	int f2 = creat("temp2.txt",O_RDONLY);
	int f3 = creat("temp3.txt",O_RDONLY);
	int f4 = creat("temp4.txt",O_RDONLY);
	int f5 = creat("temp5.txt",O_RDONLY);
	while(1);
	return 0;
}
