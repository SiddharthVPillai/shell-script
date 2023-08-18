#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char* argv[]){
	if(argc!=3){
		printf("You are useless");
		return -1;
	}	
	int fd_r = open(argv[1], O_RDONLY);
	int fd_w = open(argv[2], O_CREAT | O_WRONLY);
	if(fd_r == -1 || fd_w == -1){
		printf("Error opening file");
		return -1;
	}
	while(1){
		char buff;
		int char_read = read(fd_r, &buff, 1);
		if(char_read==0)	//reached end of file
			break;
		int char_write = write(fd_w, &buff , 1);
	}

	int fd_r_close = close(fd_r);
	int fd_w_close = close(fd_w);
	if(fd_r_close==-1 || fd_w_close==-1){
		printf("Error closing the file");
		return -1;
	}
	return 0;
}
