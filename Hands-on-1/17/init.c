#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main(){
	int fd = open("data",O_WRONLY);
	int x = 1;
	lseek(fd,0L,SEEK_SET);
       	write(fd,&x,sizeof(x));	
	return 0;
}
