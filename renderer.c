char screen[16][101]; // 101 because of the termination character (\0)
short color_screen[16][100];

char border_layer[16][101];
char *border_layer_init[16] = {
    "                                                                                                    ",
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
    "----------------------------------------------------------------------------------------------------",
};


char mario_layer[16][101];
char *mario_layer_init[16] = {
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
    // "/\\",
    // "MM",
};


char obstacles_layer[16][101];
char *obstacles_layer_init[16] = {
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
    "                           G                 G                G                                     ",
    "                                                                                                    ",
    "                                                                                                    ",
};

char ground_layer[16][101];
char *ground_layer_init[16] = {
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                            ========",
    "                                                                                      ==============",
    "                                                                                 ===================",
    "                                                                           =========================",
    "                                                                        ============================",
    "====================================================================================================",
    "                                                                                                    ",
};


char background_layer[16][101];
char *background_layer_init[16] = {
    "                                                                                                    ",
    "                                                                                                    ",
    "                                                                                                    ",
    "                  .  .                                                                              ",
    "               .. . .  .                   .  .                                                     ",
    "                . . .                     .  .  .                                                   ",
    "                   .  .                  .  .                                                       ",
    "                                               .                                                    ",
    "                                                                 . . .   .                          ",
    "                                                                 .   . .  .                         ",
    "                                                               ..  .  .. . .   .                    ",
    "                                                                       .  . . .  .                  ",
    "                                                                         .  ... ..                  ",
    "                                                                        .  .  .                     ",
    "                                                                                                    ",
    "                                                                                                    ",
};


#define NUM_LAYERS 5
enum layers {
    BG_LAYER = 0,
    GROUND_LAYER = 1,
    OBS_LAYER = 2,
    MARIO_LAYER = 3,
    BORDER_LAYER = 4,
};

char (*layers[NUM_LAYERS])[101] = {
    background_layer,
    ground_layer,
    obstacles_layer,
    mario_layer,
    border_layer
};


char **layer_init[NUM_LAYERS] = { 
    background_layer_init,
    ground_layer_init,
    obstacles_layer_init,
    mario_layer_init,
    border_layer_init,
};

int layer_colors[NUM_LAYERS] = {
    1,   // background
    2,   // ground
    3,   // obstacles
    4,   // mario
    5,   // border
};


void set_mario_position(int x, int y) {
    y = 15 - y;
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 100; x++) {
            mario_layer[y][x] = ' ';
        }
        mario_layer[y][100] = '\0';
    }

    mario_layer[y][x]     = 'M';
    mario_layer[y][x+1]   = 'M';
    mario_layer[y-1][x]   = '/';
    mario_layer[y-1][x+1] = '\\';
}


void shift_row(char *row) {
    for (int x = 0; row[x] != '\0'; x++) {
        row[x] = row[x+1];
    }
}


void scroll_level() {
    //scrolls background, ground, and obstacles layers
    for (int i = BG_LAYER; i < MARIO_LAYER; i++) {
        for (int y = 0; y < 16; y++) {
            shift_row(layers[i][y]);
        }
    }
}


void set_up_colors() {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);   // background layer
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  // ground layer
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);  // obstacles layer
    init_pair(4, COLOR_RED, COLOR_BLACK);  // mario layer
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);  // border layer
    init_pair(6, COLOR_BLACK, COLOR_BLACK);  // EMPTY layer
}


void init_layers() {
    for (int i = 0; i < NUM_LAYERS; i++) {
        for (int y = 0; y < 16; y++) {
            strncpy(layers[i][y], layer_init[i][y], 100);
            layers[i][y][100] = '\0';  // ensure null-terminated
        }
    }
}



void assemble_layers() {
    //first: clear screen matrix
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 100; x++) {
            screen[y][x] = ' ';
            color_screen[y][x] = 6;
        }
        screen[y][100] = '\0';
    }

    //then: apply layers
    for (int i = 0; i < NUM_LAYERS; i++) {
        for (int y = 0; y < 16; y++) {
            for (int x = 0; layers[i][y][x] != '\0' && x < 100; x++) {
                if (layers[i][y][x] != ' ') {
                    screen[y][x] = layers[i][y][x];
                    color_screen[y][x] = layer_colors[i];
                }
            }
        }
    }
}

int frame = 0;

void render_screen() {
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 100; x++) {
            attron(COLOR_PAIR(color_screen[y][x]));
            mvaddch(y, x, screen[y][x]);
            attroff(COLOR_PAIR(color_screen[y][x]));
        }
    }
    refresh();
}