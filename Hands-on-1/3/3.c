#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int f = create("temp.txt","RW");
	printf("fd = %d",f);
	if(f<0){
		perror("Program");
		return 1;	
	}
}
