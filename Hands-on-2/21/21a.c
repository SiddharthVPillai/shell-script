/*
============================================================================    
Name : 21a.c
Author : Siddharth V. Pillai
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
first process
Date: 3rd Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd1 = open("FIFO_1",O_WRONLY);
    int fd2 = open("FIFO_2",O_RDONLY);
    char buff[200];
    
    printf("Enter message for 2nd process: ");
    scanf("%[^\n]",buff);
    write(fd1,buff,sizeof(buff));

    read(fd2,buff,sizeof(buff));
    printf("\nMessage from 2nd process: %s",buff);
    return 0;
}