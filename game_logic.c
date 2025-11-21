int marioX = 10;
int marioY = 2;

#define TICK_SPEED 20000
#define PHYSICS_SPEED 200000

void run_game_physics(void) {
    //[todo] get input

    //update based on input/physics
    set_mario_position(marioX, marioY);
    scroll_level();
}


void run_game(void) {
    initscr();
    set_up_colors();
    clear();
    curs_set(0);


    init_layers();

    int ticks = 0;
    while (1) {
        usleep(TICK_SPEED);
        if (ticks++ >= PHYSICS_SPEED / TICK_SPEED) {
            ticks = 0;
            run_game_physics();
        }


        assemble_layers();
        render_screen();
    }
    
}