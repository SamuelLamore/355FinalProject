char screen[16][101]; // 101 because of the termination character (\0)
short color_screen[16][100];

char *border_layer[16] = {
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


char *background_layer[16] = {
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


#define NUM_LAYERS 2

char **layers[NUM_LAYERS] = { 
    background_layer,
    border_layer,
};

int layer_colors[NUM_LAYERS] = {
    1,   // background
    2    // border
};


void set_up_colors() {
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);   // background layer
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);  // border layer
}


void assemble_layers() {
    //first: clear screen matrix
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 100; x++) {
            screen[y][x] = ' ';
            color_screen[y][x] = 0;
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