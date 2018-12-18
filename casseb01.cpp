#include <ncurses.h>
#include <iostream>
#include <string>
#include "window.h"
using namespace std;

struct Ball{
	int bx, by;
	int vx, vy;
	char balle;
	Color col;
};

void myprogram(){
  int mov=0;
  Ball balle;
  int ch;
  int h=20,w=60;
  Window menu(3,30,1,0);
  Window plateau(h,w,1,7);
  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  balle.balle = '@';
  balle.bx=w/2;
  balle.by=h-2;
  balle.vx=2;
  balle.vy=-2;
  menu.print(1,1,"Tapez q pour quitter !!!",WRED);
  
  string p="...........";
  int x=(w/2)-(p.size()/2);
  int y=h-1;
  Color col=WBLUE;
  plateau.print(x,y,p,col);
  plateau.print(balle.bx, balle.by, balle.balle, col);
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      	case '1':
      		col=BMAGENTA;
      	break;

      	case '2':
			col=WCYAN;
		break;

      	case 'c':
			plateau.clear();
		break;

      	case KEY_LEFT:
      	if (x == 0) {
    			break;
    		}
    		else {
    			mvaddch(y, x+4, ' ');
    			x--;
    			mvaddch(y, x, '.');
    			break;
    		}
  //     		if(x>0){
		// 		plateau.clear();
  // 				plateau.print(balle.bx, balle.by, balle.balle, col);
  // 				plateau.print(x,y,' ');
		// 		plateau.print((x=x-1),y,p,col);}
		// break;

      	case KEY_RIGHT:
      		if(x+p.size()<w){
				plateau.clear();
  				plateau.print(balle.bx, balle.by, balle.balle, col);
  				plateau.print(x,y,' ');
				plateau.print(++x,y,p,col);}
		break;

      	case ' ':
      		plateau.clear();
        	plateau.print(balle.bx, balle.by-1, balle.balle, col);
        	plateau.print(x,y,p,col);
  		break;

      	case '\n':
      		plateau.clear();
			x=(w/2)-(p.size()/2);
  			y=h-1;
			plateau.print(x,y,p,col);
  			plateau.print(balle.bx, balle.by, balle.balle, col);
		break;

      	case '\t':
			Color tmp= menu.getCouleurBordure();
			menu.setCouleurBordure(plateau.getCouleurBordure());
			plateau.setCouleurBordure(tmp);
		break;
      }
    }
}

int main(){
  startProgramX();
  myprogram();
  // int secondsLeft = 120;
  // initscr();
  // curs_set(0);
  // do {
  //   printw("%i", secondsLeft);
  //   refresh();
  //   erase();
  //   secondsLeft--;
  //   napms(1000);
  // } while (secondsLeft > 0);
  // endwin();
  stopProgramX();
  return 0;
}