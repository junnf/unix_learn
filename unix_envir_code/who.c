#include<stdio.h>
#include<fcntl.h>
#include<utmp.h>
#include<unistd.h>

void show_info(struct utmp *loc);

int main(){
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);
    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(-1);
    }
    while(read(utmpfd, &current_record, reclen) == reclen)
        show_info(&current_record);
    close(utmpfd);
    return 0;
}

void show_info(struct utmp *loc){
    printf("%s",loc->ut_user);
    printf("%s",loc->ut_line);
    printf("\n");
}

