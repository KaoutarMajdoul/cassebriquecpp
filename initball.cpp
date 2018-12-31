#include "initball.h"
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <cstdio>
#include <sys/time.h>
#include <chrono>
#include <time.h>
#include<iostream>
#include<curses.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std ;
#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 50
#define PADDLE_LENGTH 15
#define BLOCK_LENGTH 10
#define SPACE 5
#define NBVIE 7
void init_curses() {

	initscr();             // initialize curses

	cbreak();              // pass key presses to program, but not signals
	noecho();              // don't echo key presses to screen
	keypad(stdscr, TRUE);  // allow arrow keys
	timeout(0);            // no blocking on getch()
	curs_set(0);           // set the cursor to invisible
	init_colors();
		halfdelay(1);
			nonl();
}
void finish_curses() {

	endwin();
    system("clear");
    cout << "Well done!" << endl;
}

void moveBallx(int x, bool &minus) {
	if (x == 0) {
		minus = false;
	}

	else if (x == SCREEN_WIDTH) {
		minus = true;
	}
}
void moveBally(int y, bool &minus) {
	if (y == 0) {
		minus = false;
	}
	else if (y == SCREEN_HEIGHT-1) {
		minus = true;
	}
}
