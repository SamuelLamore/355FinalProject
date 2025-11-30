int marioX = 20;
int marioY = 13;
int marioGrounded = FALSE;
int marioVelocity = 0;
int marioInvincible = FALSE;
int marioInvincibilityTimer = 0;
int marioAlive = TRUE;  // Added by Abraham
int gameWon = FALSE; // Added by Abraham
int upsideDown = FALSE;

#define TICK_SPEED       20000
#define PHYSICS_SPEED1  140000
#define PHYSICS_SPEED2  100000
#define PHYSICS_SPEED3   80000
#define PHYSICS_SPEED4   60000


int physSpeeds[] = {
    PHYSICS_SPEED1,
    PHYSICS_SPEED2,
    PHYSICS_SPEED3,
    PHYSICS_SPEED4,
};

int physSpeedCutoffs[] = {
    140,
    384,
    750,
    9999,
};


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


    debug_layer[0][11] = 'R';
    debug_layer[0][12] = '=';
    debug_layer[0][13] = '0' + r;

    debug_layer[0][15] = 'G';
    debug_layer[0][16] = '=';
    debug_layer[0][17] = '0' + g;

    debug_layer[0][19] = 'B';
    debug_layer[0][20] = '=';
    debug_layer[0][21] = '0' + b;
}


int check_ground(int x, int y) {
    if (ground_layer[y][x] != ' ') { // check ground tile
        return TRUE;
    } else {
        return FALSE;
    }
}

int check_mario_ground() {
    int addVal = (upsideDown) ? -2 : 1;
    int unit = (upsideDown) ? -1 : 1;
    if (check_ground(marioX, marioY+addVal) || check_ground(marioX+1, marioY+addVal) // check ground tiles
        || (!marioGrounded && marioVelocity <= 0 && check_ground(marioX+2, marioY+addVal) && !check_ground(marioX+2, marioY+addVal+unit))) {
        return marioGrounded = TRUE;
    } else {
        return marioGrounded = FALSE;
    }
}


int check_mario_ceiling() {
    int addVal = (upsideDown) ? 1 : -2;
    if (check_ground(marioX, marioY+addVal) || check_ground(marioX+1, marioY+addVal)) { // check ground tiles
        return TRUE;
    } else {
        return FALSE;
    }
}


void calculate_gravity() {
    int absVel = (marioVelocity > 0) ? marioVelocity : -marioVelocity; // get absolute value of the velocity
    int unitVel = (marioVelocity > 0) ? 1 : -1; // get the sign of the velocity
    check_mario_ground();
    for (int i = 0; i < absVel; i++) { // check for ground individually on each unit of velocity
        if (!upsideDown) {
            marioY -= unitVel; // double negative here: since y+ is downwards, subtracting a positive velocity makes mario go up
        } else {
            marioY += unitVel;
        }
    
        if (check_mario_ground()) { // check ground tiles
            break; // mario is grounded so stop adding velocity
        }

        if (check_mario_ceiling()) {
            marioVelocity = 0;
            return; // note the return instead of break
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


void check_wall_collisions(void) {
    if (check_ground(marioX+2, marioY) || check_ground(marioX+2, marioY-1)) {
        marioX--;
        if (marioX < 1) {
            marioAlive = FALSE;
        }
    }
}


void get_input() {
    int ch = getch();
    if (ch == ' ' && marioGrounded) {
        marioVelocity = 2;
    }
}


void check_powerup() {
    if (
        powerups_layer[marioY][marioX] != ' ' ||
        powerups_layer[marioY-1][marioX] != ' ' ||
        powerups_layer[marioY][marioX+1] != ' ' ||
        powerups_layer[marioY-1][marioX+1] != ' '
        ) { // check ground tile
            powerups_layer[marioY][marioX] = ' ';
            powerups_layer[marioY-1][marioX] = ' ';
            powerups_layer[marioY][marioX+1] = ' ';
            powerups_layer[marioY-1][marioX+1] = ' ';

            marioInvincible = TRUE;
            marioInvincibilityTimer = 75;
    }
}

// Added by Abraham
void check_enemy_collision() {
    // Check if mario hits an obstacle (enemy)
    if (!marioInvincible) {
        if (
            obstacles_layer[marioY][marioX] != ' ' ||
            obstacles_layer[marioY-1][marioX] != ' ' ||
            obstacles_layer[marioY][marioX+1] != ' ' ||
            obstacles_layer[marioY-1][marioX+1] != ' '
        ) {
            marioAlive = FALSE;
        }
    }
}

// Added by Abraham
void check_win_condition() {
    // Win condition: mario reaches the end of the level (scrollX >= LEVEL_SIZE - 100)
    if (scrollX >= LEVEL_SIZE - 100) {
        gameWon = TRUE;
    }
}


// Added by Abraham
void show_game_over_screen() {
    clear();
    attron(COLOR_PAIR(3));
    mvprintw(7, 40, "GAME OVER!");
    mvprintw(9, 38, "You have died!"); // there are 2 ways to die - hitting an obstacle, and getting crushed by the walls scrolling into the border
    // mvprintw(9, 35, "You hit an obstacle!");
    mvprintw(11, 33, "Press any key to exit...");
    attroff(COLOR_PAIR(3));
    refresh();
    
    nodelay(stdscr, FALSE);  // Wait for input
    getch();
    
    endwin();  // Clean up ncurses before exiting
    curs_set(1);  // Restore cursor
    exit(0);
}

// Added by Abraham
void show_win_screen() {
    clear();
    attron(COLOR_PAIR(7));
    mvprintw(7, 40, "YOU WIN!");
    mvprintw(9, 32, "You completed the level!");
    mvprintw(11, 32, "Press any key to exit...");
    attroff(COLOR_PAIR(7));
    refresh();
    
    nodelay(stdscr, FALSE);  // Wait for input
    getch();
    
    endwin();  // Clean up ncurses before exiting
    curs_set(1);  // Restore cursor
    exit(0);
}

void run_game_physics() {
    //update based on input/physics
    check_wall_collisions();

    set_mario_position(marioX, marioY);
    scroll_level();

    check_powerup();
    check_enemy_collision();
    check_win_condition();

    if (marioInvincible) {
        if (marioInvincibilityTimer-- <= 0) {
            marioInvincible = FALSE;
        }
    }

}


int check_if_star_exists() {
    for (int y = 2; y < 15; y++) {
        for (int x = 0; x < 100; x++) {
            if (powerups_layer[y][x] != ' ') {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void spawn_star() {
    if (check_if_star_exists()) { // can't spawn a star if one already exists
        return;
    }

    //search from y=3 to y=15 starting from the middle
    for (int i = 0; i < 6; i++) {
        if (ground_layer[9+i][99] != ' ' && ground_layer[9+i-1][99] == ' ') {
            if (ground_layer[9+i-2][99] == ' ' && rand() & 1) {
                powerups_layer[9+i-2][99] = 'S';
            } else {
                powerups_layer[9+i-1][99] = 'S';
            }
            break;
        } else if (ground_layer[9-i][99] != ' ' && ground_layer[9-i-1][99] == ' ') {
            if (ground_layer[9-i-2][99] == ' ' && rand() & 1) {
                powerups_layer[9-i-2][99] = 'S';
            } else {
                powerups_layer[9-i-1][99] = 'S';
            }
            break;
        }
    }


}

void run_game() {
    init_layers();

    int ticks = 0;
    int gameTimer = 0;
    int globalTimer = 0;
    int physSpeedIndex = 0;
    while (1) {
        globalTimer++;
        usleep(TICK_SPEED);

        //Everything in this if statement only happens once every 'PHYSICS_SPEED' microseconds. Anything outside the loop is done every 'TICK_SPEED' microseconds.
        ticks++;
        if (ticks % (PHYSICS_SPEED1 / TICK_SPEED) == 0) {
            if (!upsideDown) {
                if ((scrollX+marioX) >= 436 && (scrollX+marioX) < 695 && marioY <= 8) {
                    upsideDown = TRUE;
                    marioVelocity = 0;
                }
            } else {
                if ((scrollX+marioX) < 436 || (scrollX+marioX) > 695 || marioY > 8) {
                    upsideDown = FALSE;
                    marioVelocity = 0;
                }
            }

            get_input();
            calculate_gravity();
        }
        
        if (ticks % (physSpeeds[physSpeedIndex] / TICK_SPEED) == 0) {
            run_game_physics();
            gameTimer++;

            if (gameTimer % 20 == 0) {
                if (rand() % 10 == 0) {
                    spawn_star();
                }
            }

            //Control game speed
            if (scrollX > physSpeedCutoffs[physSpeedIndex]) {
                physSpeedIndex++;
                //play "speed up" sequence
            }
        

            // Check if game ended
            if (!marioAlive) {
                show_game_over_screen();
                break;
            }
            if (gameWon) {
                show_win_screen();
                break;
            }
        }

        if (marioInvincible) {
            update_invincibility_colors(globalTimer, marioInvincibilityTimer);
        } else {
            init_pair(4, COLOR_RED, COLOR_BLACK);  // restore mario layer
            init_pair(5, COLOR256(0, 0, 1), COLOR256(0, 0, 1));  // restore border layer
        }

        update_debug_layer();
        assemble_layers();
        render_screen();
    }
    
}