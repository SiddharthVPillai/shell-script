/*
============================================================================    
Name : 20a.c
Author : Siddharth V. Pillai
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Write into FIFO
Date: 3rd Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd = open("FIFO",O_WRONLY);
    char buff[200];
    printf("Enter message for 2nd process: ");
    scanf("%[^\n]",buff);
    write(fd,buff,sizeof(buff));
}