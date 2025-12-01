#define NUM_INTRO_LAYERS 5


char *introBlock11[4] = {
    "                                                                                   ### ###          ",
    "                                                                                   #  #  #          ",
    "                                                                                    #   #           ",
    "                                                                                    #####           ",
};
char *introBlock10[4] = {
    "                                                                             #####                  ",
    "                                                                            #   ###                 ",
    "                                                                            #   ###                 ",
    "                                                                            #######                 ",
};
char *introBlock9[4] = {
    "                                                                      ## ###                        ",
    "                                                                     #  #  #                        ",
    "                                                                     #  # #                         ",
    "                                                                     #######                        ",
};
char *introBlock8[4] = {
    "                                                            ### ###                                 ",
    "                                                            #  #  #                                 ",
    "                                                             #   #                                  ",
    "                                                             #####                                  ",
};
char *introBlock7[4] = {
    "                                                      #####                                         ",
    "                                                     #  #  #                                        ",
    "                                                     #  #  #                                        ",
    "                                                     #######                                        ",
};
char *introBlock6[4] = {
    "                                               #####                                                ",
    "                                              #  #  #                                               ",
    "                                              #  #  #                                               ",
    "                                              #######                                               ",
};
char *introBlock5[4] = {
    "                                      #####                                                         ",
    "                                     #  ####                                                        ",
    "                                     ####  #                                                        ",
    "                                     #######                                                        ",
};
char *introBlock4[4] = {
    "                               #####                                                                ",
    "                              #  ####                                                               ",
    "                              ####  #                                                               ",
    "                              #######                                                               ",
};
char *introBlock3[4] = {
    "                        #####                                                                       ",
    "                       #   ###                                                                      ",
    "                       #   ###                                                                      ",
    "                       #######                                                                      ",
};
char *introBlock2[4] = {
    "                 #####                                                                              ",
    "                #  #  #                                                                             ",
    "                #  #  #                                                                             ",
    "                #######                                                                             ",
};
char *introBlock1[4] = {
    "          #####                                                                                     ",
    "         #  #  #                                                                                    ",
    "         #   ###                                                                                    ",
    "         ####                                                                                       ",
};



char **introBlocks[11] = {
    introBlock1,
    introBlock2,
    introBlock3,
    introBlock4,
    introBlock5,
    introBlock6,
    introBlock7,
    introBlock8,
    introBlock9,
    introBlock10,
    introBlock11,
};

char intro_star_copy[5][5];
char intro_border_layer[16][101] = {
    "----------------------------------------------------------------------------------------------------",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "-                                                                                                  -",
    "----------------------------------------------------------------------------------------------------",
};


char intro_start_layer[16][101] = {
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "          _____  _____  _____  _____  _____    _____  _____ ___ ___   __ ___ _____ ___ ___          ",
    "         /  _  \\/  _  \\/   __\\/  ___>/  ___>  /  _  \\/  _  \\\\  |  /  |  |  //   __\\\\  |  /          ",
    "         |   __/|  _  <|   __||___  ||___  |  |  _  ||  |  | |   |   |  _ < |   __| |   |           ",
    "         \\__/   \\__|\\_/\\_____/<_____/<_____/  \\__|__/\\__|__/ \\___/   |__|__\\\\_____/ \\___/           ",
    "                                                                                                    ",
};

char intro_under_start_layer[16][101] = {
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
};


char intro_dash_layer[16][101] = {
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
};


char intro_logo_layer[16][101] = {
    "                                                                                                    ",
    "                                     _____ __  ______  __________                                   ",
    "                                    / ___// / / / __ \\/ ____/ __ \\                                  ",
    "                                    \\__ \\/ / / / /_/ / __/ / /_/ /                                  ",
    "                                   ___/ / /_/ / ____/ /___/ _, _/                                   ",
    "                             _____/____/\\____/_/  _/_____/_/ |_|__  _____                           ",
    "                            |__  // ____/ ____/  / __ )/ __ \\/ __ \\/ ___/                           ",
    "                             /_ </___ \\/___ \\   / __  / /_/ / / / /\\__ \\                            ",
    "                           ___/ /___/ /___/ /  / /_/ / _, _/ /_/ /___/ /                            ",
    "                          /____/_____/_____/  /_____/_/ |_|\\____//____/                             ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
};


char (*intro_layers[NUM_INTRO_LAYERS])[101] = {
    intro_dash_layer,
    intro_start_layer,
    intro_under_start_layer,
    intro_logo_layer,
    intro_border_layer,
};

int intro_layer_colors[NUM_INTRO_LAYERS] = {
    10,  // dash
    8,   // start
    9,   // under start
    2,   // logo
    5,   // border
};


// Primary Author: Samuel Lamore
// Highlights a given letter in the "PRESS ANY KEY" ascii
void assemble_start_block(int blockNum) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 100; x++) {
            intro_under_start_layer[y+11][x] = introBlocks[blockNum][y][x];
        }
    }
}


// Primary Author: Samuel Lamore
// Combines all the char layers together
void assemble_intro_layers() {
    //first: clear screen matrix
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 100; x++) {
            screen[y][x] = ' ';
            color_screen[y][x] = 6;
        }
        screen[y][100] = '\0';
    }

    //then: apply layers
    for (int i = 0; i < NUM_INTRO_LAYERS; i++) {
        for (int y = 0; y < 16; y++) {
            for (int x = 0; intro_layers[i][y][x] != '\0' && x < 100; x++) {
                if (intro_layers[i][y][x] != ' ') {
                    screen[y][x] = intro_layers[i][y][x];
                    color_screen[y][x] = intro_layer_colors[i];
                }
            }
        }
    }
}



// Primary Author: Samuel Lamore
// Shifts a given row to the right one space
void shift_row_right(char *row) {
    for (int x = 98; x >= 0; x--) {
        row[x+1] = row[x];
    }
}

// Primary Author: Samuel Lamore
// Moves forward (and backward) the dash marks in the background
void update_dashes() {
    for (int y = 0; y < 16; y++) {
        int index = 0;
        int prevOne = 1;
        if (y & 1) {
            index = 99;
            prevOne = 98;
            shift_row(intro_dash_layer[y]);
        } else {
            shift_row_right(intro_dash_layer[y]);
        }
        switch (rand() % 11) {
            case 0: case 1: case 2: case 3: case 4: case 5:
                intro_dash_layer[y][index] = intro_dash_layer[y][prevOne];
                break;
            case 6: case 7:
                intro_dash_layer[y][index] = '-';
                break;
            case 8: case 9: case 10:
                intro_dash_layer[y][index] = ' ';
                break;
        }
    }

}


// Primary Author: Samuel Lamore
// Print each character in the screen matrix
void render_intro_screen() {
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 100; x++) {
            int col = color_screen[y][x];
            if (color_screen[y][x] == 10) {
                col = 10 + (x % 6);
            }
            attron(COLOR_PAIR(col));
            mvaddch(y, x, screen[y][x]);
            attroff(COLOR_PAIR(col));
        }
    }
    refresh();
}



// Primary Author: Samuel Lamore
// Runs the loop for the title screen
void intro_screen() {
    init_pair(8, COLOR256(3, 0, 0), COLOR_BLACK);  // start layer
    init_pair(9, COLOR256(5, 0, 0), COLOR_BLACK);  // under start layer
    init_pair(10, COLOR256(1, 1, 1), COLOR_BLACK);  // dashes layer

    init_pair(11, COLOR256(1, 0, 0), COLOR_BLACK);  // dashes layer rainbow
    init_pair(12, COLOR256(1, 1, 0), COLOR_BLACK);  // dashes layer rainbow
    init_pair(13, COLOR256(0, 1, 0), COLOR_BLACK);  // dashes layer rainbow
    init_pair(14, COLOR256(0, 1, 1), COLOR_BLACK);  // dashes layer rainbow
    init_pair(15, COLOR256(0, 0, 1), COLOR_BLACK);  // dashes layer rainbow
    init_pair(16, COLOR256(1, 0, 1), COLOR_BLACK);  // dashes layer rainbow
 
    for (int i = 0; i < 100; i++) { // initialize dashes
        update_dashes();
    }

    int startBlock = 0;
    int ticks = 0;
    while (1) {
        usleep(TICK_SPEED);
        rand(); // done to scramble the rng seed

        update_dashes();
        
        if (ticks++ > 15) {
            ticks = 0;
            startBlock = (++startBlock) % 11;
        }

        assemble_start_block(startBlock);
        assemble_intro_layers();
        render_intro_screen();

        int ch = getch();
        if (ch != ERR) {
            return;
        }
    }

}