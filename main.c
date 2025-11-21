#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#include "renderer.c"
#include "game_logic.c"


void kill_program(int signum) {
    endwin();
    curs_set(1);
    exit(0);
}


int main() {
    signal(2, kill_program);
    //intro stuff should happen first
    
    //run main game logic
    run_game();

    return 0;
}