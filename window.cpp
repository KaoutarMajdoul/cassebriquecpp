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

//
// void startProgramX() {
//   initscr();             // initialize curses
//
//   cbreak();              // pass key presses to program, but not signals
//   noecho();              // don't echo key presses to screen
//   keypad(stdscr, TRUE);  // allow arrow keys
//   timeout(0);            // no blocking on getch()
//   curs_set(0);           // set the cursor to invisible
//   init_colors();
//     halfdelay(1);
//       nonl();
// }
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
// void moveBallx(int x, bool &minus) {
// 	if (x == 2) {
// 		minus = false;
// 		//miss++;
// 	}
// 	//  if (x == 5) {
// 	// minus = false;
// 	// }
// 	else if (x == 70) {
// 		minus = true;
// 	}
// }
// void moveBally(int y, bool &minus) {
// 	if (y == 7) {
// 		minus = false;
// 	}
//   // if (y > 5 ){
//   //   minus = false;
//   // }
// 	else if (y == 26) {
// 		minus = true;
// 	}
// }


void Window::update() const{
  wrefresh(win);
  wrefresh(frame);
  refresh();
}

//
// Window::Window(int h,int w, int x, int y, char c)
//   : height(h), width(w), startx(x), starty(y), bord(c)
// {
//   colorwin=WCYAN;
//   colorframe=WBLACK;
//   frame=newwin(h+2,w+2,y,x); //si victoire
//   win=subwin(frame,h,w,y+1,x+1);//si victoire
//   wbkgd(frame,COLOR_PAIR(colorwin));
//   wbkgd(win,COLOR_PAIR(colorframe));
//   wborder(frame, c,c,c,c,c,c,c,c);
//   wattron(win,COLOR_PAIR(colorwin));
//   wattron(frame,COLOR_PAIR(colorframe));
//   update();
// }
//
// Window::~Window(){
//   wborder(frame, ' ', ' ', ' ',' ',' ',' ',' ',' ');
//   wattroff(win,COLOR_PAIR(colorwin));
//   wattroff(win,COLOR_PAIR(colorframe));
//   werase(win);
//   update();
//   delwin(win);
// }
//
// void Window::print(int x, int y, std::string s, Color c) const {
//   wattron(win,COLOR_PAIR(c));
//   mvwprintw(win,y,x,s.c_str());
//   wattroff(win,COLOR_PAIR(c));
//   update();
// }
// void Window::print(int x, int y, char s, Color c) const{
//   wattron(win,COLOR_PAIR(c));
//   mvwaddch(win,y,x,s);
//   wattroff(win,COLOR_PAIR(c));
//   update();
// }
// void Window::print(int x, int y, std::string s) const{
//   mvwprintw(win,y,x,s.c_str());
//   update();
// }
// void Window::print(int x, int y, char s) const{
//   mvwaddch(win,y,x,s);
//   update();
// }
//
//
// int Window::getX() const { return startx;}
// int Window::getY() const { return starty;}
// int Window::getHauteur() const { return height;}
// int Window::getLargeur() const { return width;}
//
//
//
// // void Window::setHauteur(int h){
// //   Window::height = h;
// // }
// Color Window::getCouleurBordure() const{ return colorframe;}
// Color Window::getCouleurFenetre() const{ return colorwin;}
// void Window::setCouleurBordure(Color c){
//   colorframe=c;
//   wattron(frame,COLOR_PAIR(colorframe));
//   wborder(frame, bord,bord,bord,bord,bord,bord,bord,bord);
//   update();
// }
// void Window::setCouleurFenetre(Color c){
//   colorwin=c;
//   wattron(win,COLOR_PAIR(colorwin));
//   wbkgd(win,COLOR_PAIR(colorwin));
//   update();
// }

void Window::clear() const{  werase(win); update(); }
