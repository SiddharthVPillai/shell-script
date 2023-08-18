#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Lmao you are useless\n");
		return -1;
	}

	int fd_r = open(argv[1],O_RDONLY);
	if(fd_r==-1){
		printf("Failed to open file\n");
		return -1;
	}

	while(1){
		char buf;
		int c_r = read(fd_r,&buf,1);
		if(c_r==0)
			break;
		int c_w = write(1,&buf,1);
	}

	int fd_r_close = close(fd_r);
	if(fd_r_close==1){
		printf("Failed to close the file\n");
		return -1;
	}
	
	return 0;
}
