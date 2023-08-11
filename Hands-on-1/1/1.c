#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int sl = symlink("tempfile","tempSL");
	if(sl<0){
		perror("Failed");
		return 1;
	}

	int hl = link("tempfile","tempHL");
	if(hl<0){
		perror("Failed");
		return 1;
	}

	int e = mknod("tempFIFO",S_IFIFO|0666,0);
	if(e<0)	perror("Failed");
	return 0;
}
