/*
============================================================================    
Name : 27a.c
Author : Siddharth V. Pillai
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 7th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<error.h>

int main(){
    int msgid,size;
    key_t k;

    struct msg{
        long int mtype;
        char msg[80];
    }mq;

    k = ftok(".",'a');
    msgid = msgget(k,0);
    printf("Enter the message type to receive: ");
    scanf("%ld",&mq.mtype);

    msgrcv(msgid,&mq, sizeof(mq.msg),mq.mtype,0);
    printf("Message type: %ld",mq.mtype);
    perror(" ");
    printf("\nMessage text: %s",mq.msg);
    return 0;
}