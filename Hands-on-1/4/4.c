#include<stdio.h>
#include<fcntl.h>

int main(){
	int f1 = open("temp.txt",O_EXCL,"w");
	int f2 = open("temp2.txt",O_EXCL,"w");		
	int f3 = open("temp.txt",O_EXCL,"w");
		
	if(f1<0){
		perror("Program");
		return 1;
	}
	printf("f1 = %d",f1);
	printf("\n");

	if(f2<0){
		perror("Program");
	}
	printf("f2 = %d",f2);
	printf("\n");
	
	if(f3<0){
		perror("Program");
	}
	printf("f3 = %d",f3);
	return 0;
}