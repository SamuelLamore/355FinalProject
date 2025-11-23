#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//rgb values from 0-5 for each channel
#define COLOR256(r, g, b) (16 + 36*r + 6*g + b)


#include "renderer.c"
#include "game_logic.c"


void kill_program(int signum) {
    endwin();
    curs_set(1);
    exit(0);
}


int main() {
    signal(2, kill_program);

    initscr();
    set_up_colors();
    clear();
    curs_set(0);

    //[TODO] Before run_game(), there should be an intro screen that only ends if you enter a key

    //run main game logic
    run_game();

    return 0;
}