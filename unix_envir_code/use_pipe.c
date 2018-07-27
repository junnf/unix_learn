#include <stdio.h>

#define BUFSIZE 256

int main(int argc, char *argv[])
{
    int pipefd[2];
    char buf[BUFSIZE];
    int state_pipe = 0;
    int len = 0;
    int read_len;
    if(pipe(pipefd) == -1){
        perror("cannot get a pipe");
        exit(1);
    }
    switch (fork()) {
        case -1:
            perror("cannot get a fork");
            exit(2);
            break;
        case 0:
            while (1) {
                if(write(pipefd[1],"from child write", strlen("from child write") ) != strlen("from child write")){
                    perror("cannot write to fd1");
                    exit(3);

                }
                sleep(10);

            }
            break;
        default:
            while (1) {
                if(write(pipefd[1],"from parent write", strlen("from parent write") ) != strlen("from parent write")){
                    perror("cannot write to fd1");
                    exit(3);

                }
                sleep(2);
                if((read_len = read(pipefd[0], buf, BUFSIZE)) <= 0)
                    break;
                write(1, buf, read_len);

            }

    }
    return 0;
}
