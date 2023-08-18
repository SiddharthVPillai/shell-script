#include<unistd.h>
#include<string.h>
const int MAX_SIZE = 1024;

int main(){
	char buf[MAX_SIZE];
	
	read(0,buf,MAX_SIZE);
	write(1,buf,strlen(buf)+1);
	return 0;
}
