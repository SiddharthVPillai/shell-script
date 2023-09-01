#include<unistd.h>

int main(){
	execle("/usr/bin/ls","-R","-l",NULL,NULL);
	return 0;
}
