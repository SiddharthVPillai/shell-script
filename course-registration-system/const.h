char* displayMenu(){
    char *msg = "\t\t--------Welcome---------\n1.Admin\n2.Faculty\n3.Student\nEnter choice: ";
    return msg;
}

char* displayAdminMenu(){
    char *msg = "\t\t-------Welcome Admin---------\n1.Add Student\n2.View Student\n3.Add faculty\n4.View faculty details\n5.Activate Student\n6.Block Student\n7.Modify Student Details\n8.Modify Faculty Details\n9.Logout and exit";
    return msg;
}