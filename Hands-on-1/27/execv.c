#include<unistd.h>

int main(){
	char * ar[] = {"ls","-R","-l",(char*)0};
	execv("/usr/bin/ls",ar);
	return 0;
}
