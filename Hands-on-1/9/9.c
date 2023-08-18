#include<sys/stat.h>
#include<stdio.h>
#include<time.h>
int main(int argc, char* argv[]){
	if(argc!=2){
		printf("USELESS\n");
		return -1;
	}

	struct stat sb;
	stat(argv[1],&sb);
	printf("I-node number: %lu\n",sb.st_ino);
	printf("No of hardlinks: %lu\n",sb.st_nlink);
	printf("UID: %u\n",sb.st_uid);
	printf("GID: %u\n",sb.st_gid);
	printf("Size: %luB\n",sb.st_size);
	printf("Block size: %lu\n",sb.st_blksize);
	printf("No. of blocks: %lu\n",sb.st_blocks);
	
	time_t access_time = sb.st_atime;
	struct tm *a_info = localtime(&access_time);
	char a_buffer[50];
	strftime(a_buffer,sizeof(a_buffer),"%Y-%m-%d %H:%M:%S",a_info);
	printf("Time of last access: %s\n",a_buffer);


	time_t mod_time = sb.st_mtime;
	struct tm *m_info = localtime(&mod_time);
	char m_buffer[50];
	strftime(m_buffer,sizeof(m_buffer),"%Y-%m-%d %H:%M:%S",m_info);
	printf("Time of last modification: %s\n",m_buffer);

	time_t ch_time = sb.st_ctime;
	struct tm *c_info = localtime(&ch_time);
	char c_buffer[50];
	strftime(c_buffer,sizeof(c_buffer),"%Y-%m-%d %H:%M:%S",c_info);
	printf("Time of last change: %s\n",c_buffer);

	return 0;

}
