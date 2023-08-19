#include<stdio.h>
#include<sys/select.h>
#include<unistd.h>
int main(){
	fd_set rfds;
	struct timeval tv;
	int retval;
	char buf[60];
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;
	retval = select(1,&rfds,NULL,NULL,&tv);
	read(0,buf,60);
	if(retval){
		printf("Data available within 10 sec\n");
		printf("%s",buf);
	}
	else
		printf("Data not available within 10 sec\n");
	return 0;
}
