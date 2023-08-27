#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
struct train{
	int train_no;
	int ticket_no;
}t;
int main(){

	int fd = open("data.txt",O_RDWR);
	printf("Enter train number: \n");
	int tno;
	scanf("%d",&tno);

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (tno-1)*sizeof(t);
	lock.l_len = sizeof(t);
	lock.l_pid = getpid();

	lseek(fd,(tno-1)*sizeof(t),SEEK_SET);
	read(fd,&t,sizeof(t));
	printf("Before critical section\n");

	fcntl(fd,F_SETLKW,&lock);
	printf("Ticket number: %d\n",t.ticket_no);
	t.ticket_no++;
	lseek(fd,-1*sizeof(t),SEEK_CUR);
	write(fd,&t,sizeof(t));
	printf("Inside Critical Section\n");
	getchar();
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Outside Critical Section\n");
}
