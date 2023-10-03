/*
============================================================================    
Name : 19c.c
Author : Siddharth V. Pillai
Description : Create a FIFO file by
c. mknod system call
Date: 3rd Oct, 2023.
============================================================================
*/

#include<sys/stat.h>
#include<fcntl.h>
int main(){
    mknod("nod_prog",S_IFIFO | 0666,0);
    return 0;
}