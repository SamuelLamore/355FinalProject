void run_game(void) {
    initscr();
    set_up_colors();
    clear();

    while (1) {
        usleep(20000);
        assemble_layers();
        render_screen();

        getch();
        endwin();
        break;
    }
    
}