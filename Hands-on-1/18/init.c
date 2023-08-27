#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	struct train{
		int train_no;
		int ticket_no;
	}t[4];
	int fd = open("data.txt",O_RDWR);
	for(int i=0;i<4;i++){
		t[i].train_no = i+1;
		t[i].ticket_no = 0;
	}
	write(fd,t,sizeof(t));
	close(fd);
}
