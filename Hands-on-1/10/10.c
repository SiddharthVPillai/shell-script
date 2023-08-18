#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
	int fd = open("seek",O_CREAT|O_RDWR);
	char buf[200];
	read(0,buf,20);
	write(fd,buf,10);

	int l_seek = lseek(fd,10L,SEEK_CUR);
	
	write(fd,buf+10,10);

	printf("Return value of lseek: %d",l_seek);
	return 0;
}
