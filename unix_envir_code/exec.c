#include <stdio.h>
int main(void){
    char *list[3];
    list[0] = "ls";
    list[1] = "-l";
    list[2] = 0;
    execvp("ls", list);
    printf("nnn");

}
