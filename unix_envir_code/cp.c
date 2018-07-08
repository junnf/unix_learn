#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define COPYMODE 0644

int main(int argc, char **argv){
    char *src = argv[1];
    char *dst = argv[2];
    char buf[4096];

    int fd1, fd2;
    if((fd1=open(src, O_RDONLY)) == -1){
        exit(1);
    }
    if((fd2 = create(dst, COPYMODE)) == -1){
        exit(2);
    }





}
