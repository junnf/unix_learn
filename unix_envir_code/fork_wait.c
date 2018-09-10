#include <stdio.h>

void child_code(){
    sleep(5);
    printf("%d\n", getpid() );
}

void parent_code(){
    wait(NULL);
    printf("%d\n", getpid() );
}

int main(int argc, char *argv[])
{
    int fork_ret;
    fork_ret = fork();
    if (-1 == fork_ret) {
        perror("fork");
    } else if( 0 == fork_ret ){
       child_code();
    } else{
       parent_code();
    }


    return 0;
}
