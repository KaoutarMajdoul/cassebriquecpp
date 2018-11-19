#include "window.h"
#include <iostream>
#include <string>
#include <ncurses.h>




using namespace std ;

// int tailleROW()
// {
//   //Structure dans laquelle sera mit les informations du terminal
//   struct winsize w;
//   //Recuperghghgation des informations
//   ioctl(0, TIOCGWINSZ, &w);
//   //On affiche pour l'exemple
//   // printf ("lines %d\n", w.ws_row);
//   // printf ("columns %d\n", w.ws_col);
//   //Fin du programme
//   return w.ws_row;
// }
// int tailleCOL(){
//   //Structure dans laquelle sera mit les informations du terminal
//   struct winsize w;
//   //Recuperation des informations
//   ioctl(0, TIOCGWINSZ, &w);
//   return w.ws_col ;
// }

// void myprogram(){
//   int ch;
//   int h=tailleROW(),w=tailleCOL();


void myprogram(){
  int ch;
  int h=20,w=70;
  Window menu(3,20,75,20);
  Window plateau(h,w,1,6);
  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Tapez q pour quitter !!!",WBLUE);
  string p="XXXXXXXXXXXXXXXXXXXXXXXXX";
  int x=w/2-(p.size()/2),y=h-1;


  char balle ='@';
  int bx = w/2, by =h-2;


  Color col=WBLUE;

  Color colb = WRED; 
  plateau.print(x,y,p,col);
  plateau.print(bx,by,balle,colb);  
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
 //      case KEY_UP:
	// plateau.print(x,y,' ');
	// plateau.print(x,--y,p,col);
	// break;
 //      case KEY_DOWN:
	// plateau.print(x,y,' ');
	// plateau.print(x,++y,p,col);
	// break;
      case KEY_LEFT:
	plateau.print(x,y,' ');
	plateau.print(--x,y,p,col);
	break;
      case KEY_RIGHT:
	plateau.print(x,y,' ');
	plateau.print(++x,y,p,col);
	break;
      case '\n':
	x=w/2,y=h/2;
	plateau.print(x,y,p,col);
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
  stopProgramX();
  return 0;
}
