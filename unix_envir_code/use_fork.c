#include <stdio.h>

int main(int argc, char *argv[])
{
    int fork_ret;
    int my_pid;
    int ret_from_fork;
    my_pid = getpid();
    printf("bofore %d \n", my_pid);
    ret_from_fork = fork();
    /* if (ret_from_fork = 0) */
    printf("%d %d\n",getpid(), ret_from_fork );
    return 0;
}
