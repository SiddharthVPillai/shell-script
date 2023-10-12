#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>


int main(){
    int nsd;
    nsd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(9009);
    serv.sin_addr.s_addr = INADDR_ANY;

    connect(nsd,(struct sockaddr*)&serv,sizeof(serv));

    char buff[200];



    int bytes_read = read(nsd,buff,sizeof(buff));
    while(bytes_read>1){
        printf("%s",buff);
        char in;
        scanf("%c",&in);
        write(nsd,&in,sizeof(in));
        bytes_read = read(nsd,buff,sizeof(buff));
    }

    // read(nsd,buff,sizeof(buff));
    // printf("\n%s",buff);
    return 0;

}