#include "window.h"
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


void printn(int x){
printf("hello : %d\n", x);
}


void init_colors(void)
{

  start_color();
  init_pair(WBLACK,   COLOR_WHITE, COLOR_BLACK);
  init_pair(WCYAN,    COLOR_WHITE, COLOR_CYAN);
  init_pair(WBLUE,    COLOR_WHITE, COLOR_BLUE);
  init_pair(WYELLOW,  COLOR_WHITE, COLOR_YELLOW);
  init_pair(WGREEN,   COLOR_WHITE, COLOR_GREEN);
  init_pair(WMAGENTA, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(WRED,     COLOR_WHITE, COLOR_RED);
  init_pair(BWHITE,   COLOR_BLACK, COLOR_WHITE);
  init_pair(BCYAN,    COLOR_BLACK, COLOR_CYAN);
  init_pair(BBLUE,    COLOR_BLACK, COLOR_BLUE);
  init_pair(BYELLOW,  COLOR_BLACK, COLOR_YELLOW);
  init_pair(BGREEN,   COLOR_BLACK, COLOR_GREEN);
  init_pair(BMAGENTA, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(BRED,     COLOR_BLACK, COLOR_RED);
}


void init_paddle(int paddle, int paddley, int paddlex){

  for (paddle = 0; paddle < 6; paddle++) {
    mvaddch(paddley, paddlex+paddle, 'X');
  }
}

void init_briques(int brique, int briquey, int briquex){

  for (brique = 0; brique < 6; brique++) {
    mvaddch(briquey, briquex+brique, 'B');
    mvaddch(briquey+rand()%10+0, briquex+brique+rand()%60+0, 'B');
    mvaddch(briquey+rand()%10+0, briquex+brique+rand()%60+0, 'B');
  }
}


void stopProgramX() {
  refresh();
  getch();
  endwin();
  cout << "Partie terminée !" << endl;
}



void Window::update() const{
  wrefresh(win);
  wrefresh(frame);
  refresh();
}



void Window::clear() const{  werase(win); update(); }
