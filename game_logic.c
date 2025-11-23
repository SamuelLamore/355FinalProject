int marioX = 10;
int marioY = 13;
int marioGrounded = FALSE;
int marioVelocity = 0;

#define TICK_SPEED 20000
#define PHYSICS_SPEED 140000


void update_debug_layer() {
    if (marioGrounded) {
        debug_layer[0][2] = 'G';
    } else {
        debug_layer[0][2] = ' ';
    }


    char scroll[4];
    snprintf(scroll, sizeof(scroll), "%03d", scrollX);
    debug_layer[0][99] = scroll[2];
    debug_layer[0][98] = scroll[1];
    debug_layer[0][97] = scroll[0];


    debug_layer[0][5] = 'V';
    debug_layer[0][6] = '=';
    if (marioVelocity < 0) {
        debug_layer[0][7] = '-';
    } else {
        debug_layer[0][7] = ' ';
    }

    debug_layer[0][8] = '0' + ((marioVelocity > 0) ? marioVelocity : -marioVelocity);

}


int check_ground(int x, int y) {
    if (ground_layer[y][x] != ' ') { // check ground tile
        return TRUE;
    } else {
        return FALSE;
    }
}

int check_mario_ground() {
    if (check_ground(marioX, marioY+1) || check_ground(marioX+1, marioY+1)) { // check ground tiles
        return marioGrounded = TRUE;
    } else {
        return marioGrounded = FALSE;
    }
}


void calculate_gravity() {
    int absVel = (marioVelocity > 0) ? marioVelocity : -marioVelocity; // get absolute value of the velocity
    int unitVel = (marioVelocity > 0) ? 1 : -1; // get the sign of the velocity
    check_mario_ground();
    for (int i = 0; i < absVel; i++) { // check for ground individually on each unit of velocity
        marioY -= unitVel; // double negative here: since y+ is downwards, subtracting a positive velocity makes mario go up
    
        if (check_mario_ground()) { // check ground tiles
            break; // mario is grounded so stop adding velocity
        }
    }

    if (!marioGrounded) {
        if (marioVelocity >= 0) {
            marioVelocity -= 1; // the effect of gravity, if mario is not on the ground already
        }
    } else {
        marioVelocity = 0;
    }
}

void get_input() {
    int ch = getch();
    if (ch == ' ' && marioGrounded) {
        marioVelocity = 2;
    }
}

void run_game_physics(void) {
    get_input();
    calculate_gravity();

    //update based on input/physics
    //[TODO] detect if mario is horizontally colliding with the ground/walls, push him back if so

    set_mario_position(marioX, marioY);
    scroll_level();

    //[TODO] detect if mario is on top of a star (need a dedicated star layer most likely), activate invincibility if so
    //[TODO] detect if mario is on top of something in the obstacles layer, kill him if so
}


void run_game(void) {
    //input stuff
    noecho();
    nodelay(stdscr, TRUE);

    init_layers();

    int ticks = 0;
    int gameTimer = 0;
    while (1) {
        usleep(TICK_SPEED);

        //Everything in this if statement only happens once every 'PHYSICS_SPEED' microseconds. Anything outside the loop is done every 'TICK_SPEED' microseconds.
        if (ticks++ >= PHYSICS_SPEED / TICK_SPEED) {
            ticks = 0;
            run_game_physics();
            gameTimer++;

            //[TODO] randomly generate a star powerup
        }

        update_debug_layer();
        assemble_layers();
        render_screen();
    }
    
}