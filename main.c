#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>


#include "renderer.c"
#include "game_logic.c"


int main() {
    //intro stuff should happen first
    
    //run main game logic
    run_game();

    return 0;
}