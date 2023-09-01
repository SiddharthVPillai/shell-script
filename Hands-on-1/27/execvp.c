#include<unistd.h>

int main(){
	char *ar[] = {"ls","-R","-l",NULL};
	execvp("ls",ar);
	return 0;
}
