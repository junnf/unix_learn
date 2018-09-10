#include <stdio.h>
#include <ncurses.h>

int main(void){
    initscr();
    int i;
    clear();
    move(1,1);
    addstr("hello");
    move(10,1);
    addstr("hello");
    refresh();
/*     for (i = 0; i < LINES; i++) { */
       /* move(i, i+1) ; */
       /* if(i%2 == 1) */
           /* standout(); */
       /* addstr("Hello world"); */
       /* if(i % 2 == 1) */
           /* standend(); */
        /* sleep(1); */
        /* refresh(); */
    /* } */
/* [>     e <]ndwin(); */
}
