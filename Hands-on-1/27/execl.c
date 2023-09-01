#include<stdio.h>
#include<unistd.h>

int main(){
	execl("/usr/bin/ls","ls","-R","-l",(char*)0);
	return 0;
}
