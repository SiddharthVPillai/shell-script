/*
============================================================================
Name : 4.c
Author : Siddharth V. Pillai
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 11th Aug, 2023.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
	int f1 = open("temp.txt",O_RDWR);
	int f2 = open("temp.txt",O_CREAT | O_EXCL);		
		
	if(f1<0){
		perror("Program");
		return 1;
	}
	printf("f1 = %d",f1);
	printf("\n");

	if(f2<0){
		perror("Program");
		exit(1);
	}
	printf("f2 = %d",f2);
	printf("\n");
	
	return 0;
}
