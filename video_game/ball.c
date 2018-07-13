#include <stdio.h>
#include <ncurses.h>
#include <signal.h>
#include <sys/time.h>

#define ROW 10
#define RIGHTEDGE 30
#define LEFTEDGE 10

char *message = "hello";
char *blank = "     ";
int pos =LEFTEDGE;
int dir = +1;

struct itimeval {
    struct timeval it_value;
    struct timeval it_interval;
};

int main(void){
    initscr();
    clear();

    while (1) {
        move(ROW, pos);
        addstr(message);
        move(LINES - 1, COLS - 1);
        refresh();
        sleep(1);
        move(ROW,pos);
        addstr(blank);
        pos += dir;
        if(pos >= RIGHTEDGE)
            dir = -1;
        if(pos <= LEFTEDGE)
            dir = +1;
    }

   /*  int i; */
    /* initscr(); */
    /* clear(); */
    /* for (i = 0; i < LINES; i++) { */
       /* move(i, i+1) ; */
       /* if(i%2 == 1) */
           /* standout(); */
       /* addstr("Hello world"); */
       /* if(i % 2 == 1) */
           /* standend(); */
       /* refresh(); */
       /* sleep(1); */
       /* move(i,i+1); */
       /* addstr("                  "); */
    /* } */
    /* endwin(); */
}
