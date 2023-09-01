#include<unistd.h>

int main(){
	execlp("ls","ls","-R","-l",NULL);
	return 0;
}
