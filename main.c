#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

//rgb values from 0-5 for each channel
#define COLOR256(r, g, b) (16 + 36*r + 6*g + b)


#include "helper_functions.c"
#include "renderer.c"
#include "game_logic.c"
#include "intro.c"



// Primary Author: Samuel Lamore
// Kills Program when ctrl+c is pressed
void kill_program(int signum) {
    endwin();
    curs_set(1);
    exit(0);
}


// Primary Author: Samuel Lamore
// The main method
int main() {
    signal(2, kill_program);

    initscr();
    set_up_colors();
    clear();
    curs_set(0);

    //input stuff
    noecho();
    nodelay(stdscr, TRUE);

    intro_screen();

    //run main game logic
    run_game();

    return 0;
}