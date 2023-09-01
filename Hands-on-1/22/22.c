#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
int main(){
	int fd = open("file.txt",O_RDWR);
       	if(!fork()){
		write(fd,"hello from child\n",17);
	}	
	else{
		write(fd,"hello from parent\n",18);
		wait(0);
		close(fd);
		fd = open("file.txt",O_RDONLY);
		char buf[50];
		read(fd,buf,sizeof(buf));
		printf("File content: \n%s",buf);
	}
	return 0;
}
