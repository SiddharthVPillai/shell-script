#define ROOT "root"
#define PASS "1234"




int validate(char id[],char pass[]){
    if(strcmp(ROOT,id)==0 && strcmp(PASS,pass)==0)  return 1;
    return 0;
}

void admin(int cl){
    char id[5],pass[5];
    write(cl,"Enter login id: ",17);
    int bytes_read = read(cl,id,sizeof(id));
    id[bytes_read] = '\0';
    write(cl,"Enter password: ",17);
    bytes_read = read(cl,pass,sizeof(pass));
    pass[bytes_read] = '\0';
    
    if(validate(id,pass)){
        write(cl,displayAdminMenu(),sizeof(displayAdminMenu()));
        char opt;
        bytes_read = (cl,&opt,sizeof(opt));
        int op = atoi(&opt);
    }
}