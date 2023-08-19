#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	int fd = open("file",O_RDWR);
	if(fd==-1){
		printf("Error opening the file\n");
		return -1;
	}
	
	int fl = fcntl(fd,F_GETFL,0);
	if(fl==-1){
		printf("\nError getting file flags");
		return -1;
	}
	
	if(fl & O_WRONLY){
		printf("Write-only mode\n");
	}
	else if(fl & O_RDONLY){
		printf("Read-only mode\n");
	}
	else if(fl & O_RDWR){
		printf("Read write mode\n");
	}
	
	close(fd);
	return 0;
}
