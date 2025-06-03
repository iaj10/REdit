#include "gui_ncs.h"
#include <ncurses.h>
#include <stdlib.h>

void init_colors() {
    start_color();

    // Check if terminal supports colors
    if (!has_colors() || !can_change_color()) {
        endwin();
        fprintf(stderr, "Your terminal does not support color changes.\n");
        exit(1);
    }

    // Define some custom Catppuccin Mocha colors (RGB values 0-1000)
    init_color(COLOR_BLACK,   118, 118, 180); // base
    init_color(COLOR_WHITE,   804, 839, 956); // text
    init_color(COLOR_RED,     953, 545, 659); // red
    init_color(COLOR_GREEN,   651, 890, 631); // green
    init_color(COLOR_CYAN,    490, 709, 964); // blue (for functions maybe)

    // Define color pairs
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // default
    init_pair(2, COLOR_CYAN, COLOR_BLACK); // strings
    init_pair(3, COLOR_RED,   COLOR_BLACK); // errors
    init_pair(4, COLOR_WHITE,  COLOR_BLACK); // input
}

void curses_init(){
    initscr();
    noecho();                   
    raw();
    curs_set(2);
    init_colors();
    //start_color();
    //init_pair(1, COLOR_CYAN, COLOR_BLACK); /*COLOR codes for ncurses*/
    //init_pair(2, COLOR_GREEN, COLOR_BLACK);
    //init_pair(3, COLOR_WHITE, COLOR_BLACK);

}

/*Renders the window from the first line i.e. Y = 0, and the "start" buffer pointer.*/
void loadwin(buffer *bf, int y){
	clear();
	attron(COLOR_PAIR(4));
	int x = 0;
	while(bf != NULL){
		mvprintw(y, x, "%s", bf->line);
		y++;
		bf = bf->next;
	}

	refresh();
}


/*not used, was initially supposed to put tildes on each line, but later discarded.*/
void tildeall(){
	int x = 0, y = 0, ht;
	getmaxyx(stdscr, ht, x);
	x = 0;
	for(y = 0; y < ht; y ++){
		mvaddch(y, x, '~');
	}
	refresh();
	move(0, 0);
}
