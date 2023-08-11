#include<unistd.h>
#include<fcntl.h>

int main(){
	int f1 = open("temp1.txt",O_CREAT,"R");
	int f2 = open("temp2.txt",O_CREAT,"R");
	int f3 = open("temp3.txt",O_CREAT,"R");
	int f4 = open("temp4.txt",O_CREAT,"R");
	int f5 = open("temp5.txt",O_CREAT,"R");
	while(1);
	return 0;
}
