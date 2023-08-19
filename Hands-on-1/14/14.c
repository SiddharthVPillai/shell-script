#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main(int argc, char* argv[]){
	if(argc !=2){
		printf("Useless individual\n");
		return -1;
	}
	
	struct stat file_info;
	
	if(stat(argv[1],&file_info)==-1){
		printf("Error getting information\n");
		return -1;
	}

	if(S_ISREG(file_info.st_mode)){
		printf("Regular file\n");
	}
	else if(S_ISDIR(file_info.st_mode)){
		printf("Directory\n");
	}
	else if(S_ISCHR(file_info.st_mode)){
		printf("Character file\n");
	}
	else if(S_ISBLK(file_info.st_mode)){
		printf("Block device\n");
	}
	else if(S_ISFIFO(file_info.st_mode)){
		printf("FIFO or Pipe\n");
	}
	else if(S_ISLNK(file_info.st_mode)){
		printf("Symbolic link\n");
	}
	else if(S_ISSOCK(file_info.st_mode)){
		printf("Socket\n");
	}
	else{
		printf("Unknown type");
	}
	return 0;
}
