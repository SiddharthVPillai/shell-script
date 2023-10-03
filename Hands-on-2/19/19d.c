/*
============================================================================    
Name : 19d.c
Author : Siddharth V. Pillai
Description : Create a FIFO file by
d. mkfifo library function
Date: 3rd Oct, 2023.
============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>

int main(){
    mkfifo("fifo_prog", 0777);
    return 0;
}