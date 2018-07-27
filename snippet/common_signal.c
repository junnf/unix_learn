#include <signal.h>
#include <stdio.h>

void handl(){

}

void common_sig(){
    struct sigaction newhandler;
    sigset_t blocked;
    newhandler.sa_handler = handl;
    newhandler.sa_flags = SA_RESETHAND | SA_RESTART;
    sigemptyset(&blocked);
    /* add some signal-handler  */
    sigaddset(&blocked, SIGQUIT);
    newhandler.sa_mask = blocked;
}

int main(int argc, char *argv[])
{

    return 0;
}
