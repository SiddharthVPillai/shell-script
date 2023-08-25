#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(void){
	int fd = open("file",O_RDWR);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside Critical Section\n");
	getchar();
	printf("After critical section\n");
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	return 0;
}
