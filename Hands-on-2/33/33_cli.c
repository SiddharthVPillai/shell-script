/*
============================================================================    
Name : 33_cli.c
Author : Siddharth V. Pillai
Description : Write a program to communicate between two machines using socket.
client program
Date: 9th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
    int nsd;
    nsd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(9009); 
    serv.sin_addr.s_addr = INADDR_ANY;

    connect(nsd, (struct sockaddr *)&serv, sizeof(serv));

    char serv_res[256];
    recv(nsd, serv_res,sizeof(serv_res),0);

    printf("Data from server: %s",serv_res);
    close(nsd);
    return 0;
}