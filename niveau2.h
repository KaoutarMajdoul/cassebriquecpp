#ifndef __NIVEAU2_H
#define __NIVEAU2_H

extern "C" {
#include <curses.h>
}
#include <string>
#include<iostream>
#include<curses.h>
#include <ncurses.h>
#include<fstream>
#include<cstring>

using namespace std;

void printniveau(int x);
void startNIVEAU2();


class Niveau2{
public :
void printniveau(int x);


~Niveau2();

};
#endif
