#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <sys/time.h>


#define ROW              30
#define RIGHTEDGE        70
#define LEFTEDGE         10
#define MID              ((LEFTEDGE + RIGHTEDGE)/2)
#define BAR              "|_____|"
#define MEDIUM_BAR       "|__________|"

#define BALL             "O"
#define BAR_CLEAR        "       "
#define BALL_CLEAR       " "

/* lose */
#define FALL            0

typedef struct ball{

    int pre_x;
    int pre_y;
    int cur_x;
    int cur_y;
    char symbol;
};

struct itimeval {
    struct timeval it_value;
    struct timeval it_interval;
};

int pos_x = 0, pos_y = 0;

struct ball i_ball;
int doo = 1;

int set_ticker(int n_ms){
    struct itimeval new_timeset;
    long ns, nus;
    ns = n_ms / 1000;
    nus = (n_ms % 1000) * 1000L;
    new_timeset.it_interval.tv_sec = ns;
    new_timeset.it_interval.tv_usec = nus;
    new_timeset.it_value.tv_sec = ns;
    new_timeset.it_value.tv_usec = nus;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}

int set_ticker_border_test(int n_ms){
    struct itimeval new_timeset;
    long ns, nus;
    ns = n_ms / 1000;
    nus = (n_ms % 1000) * 1000L;
    new_timeset.it_interval.tv_sec = ns;
    new_timeset.it_interval.tv_usec = nus;
    new_timeset.it_value.tv_sec = ns;
    new_timeset.it_value.tv_usec = nus;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}

void ball_move(){
    /* init ball move */
    if (i_ball.cur_y == 1) {
        mvaddch(i_ball.cur_y+1, i_ball.cur_x-1,' ');
        doo = 2;
    }
    if(doo == 1){
        mvaddch(i_ball.cur_y+1, i_ball.cur_x-1,' ');
        mvaddch(i_ball.cur_y, i_ball.cur_x,'O');
        i_ball.cur_y--;
        i_ball.cur_x++;
        refresh();
    }
    if(doo == 2){
        mvaddch(i_ball.cur_y-1, i_ball.cur_x-1,' ');
        mvaddch(i_ball.cur_y, i_ball.cur_x,'O');
        i_ball.cur_y++;
        i_ball.cur_x++;
        refresh();
    }
}

void bar_move_left(){

    //clear position
    if(pos_x <= LEFTEDGE)
        return;
    move(pos_y, pos_x + 1);
    addstr(BAR_CLEAR);
    move(pos_y, pos_x - 1);
    addstr(BAR);
        /* addstr(" "); */
    refresh();
    pos_x -= 1;
}

void bar_move_right(){
    //clear position
    if(pos_x >= RIGHTEDGE)
        return;
    move(pos_y, pos_x - 1);
    addstr(BAR_CLEAR);
    move(pos_y, pos_x + 1);
    addstr(BAR);
        /* addstr(" "); */
    refresh();
    pos_x += 1;
}

int ball_position(int position_x){
    return (position_x + 3);
}

char lose(int bar_position, int ball_position){

    if(ball_position < bar_position){
        return (bar_position > ball_position? FALL : 1);
    }
    else{
        if ((ball_position - bar_position) > 7 )
            return FALL;
        else
            return 1;
    }
}

int main(void){

    char c ;
    i_ball.pre_x = MID + 3;
    i_ball.pre_y = ROW - 1;
    i_ball.cur_x = MID + 3;
    i_ball.cur_y = ROW - 2;

    initscr();
    clear();

    move(ROW, MID);
    pos_y = ROW, pos_x = MID;
    addstr(BAR);
    refresh();
    noecho();
    crmode();

    signal(SIGALRM, ball_move);
    set_ticker(100);

    while (1) {
        c = getch();
        if(c == 'h')
            bar_move_left();
        else if (c == 'l') {
            bar_move_right();
        } else {
            addstr(" ");
        }
   }
}
