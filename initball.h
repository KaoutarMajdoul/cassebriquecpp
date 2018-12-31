#ifndef __INITBALL_H
#define __INITBALL_H

extern "C" {
#include <curses.h>
}
#include <string>
#include<iostream>
#include<curses.h>
#include <ncurses.h>
#include<fstream>
#include<cstring>
#include "window.h"
using namespace std;



void init_curses();
void finish_curses();
void moveBallx(int x, bool &minus);
void moveBally(int y, bool &minus);



#endif
