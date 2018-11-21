#include "window.h"
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <cstdio>
#include <sys/time.h>
#include <chrono>
#include <time.h>




using namespace std ;

// int tailleROW()
// {
//   //Structure dans laquelle sera mit les informations du terminal
//   struct winsize w;
//   //Recuperation des informations
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
  Window menu(15,25,75,10);
  //nb ligne, longueur,x,y
  Window plateau(h,w,1,6);
  
  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  
  menu.print(1,1,"Tapez q pour quitter !!!",WBLUE);
  menu.print(2,2,"TIMER : ",WBLUE);

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
      if(x>0){
       plateau.clear();
      
plateau.print(bx,by,balle,colb); 
  plateau.print(x,y,' ');
  plateau.print(--x,y,p,col); }
  break;
      case KEY_RIGHT:
  if(x+p.size() < w){
       plateau.clear();
plateau.print(bx,by,balle,colb); 
  plateau.print(x,y,' ');

  plateau.print(++x,y,p,col); }
  break;

  case ' ':
      while(by > 0){        
plateau.clear();
plateau.print(x,y,p,col);
plateau.print(bx,--by,balle,colb); 
usleep(100000);

// sleep(1);
}  

while (by < h-2){
plateau.clear();
plateau.print(x,y,p,col);
plateau.print(bx,++by,balle,colb); 
usleep(100000); }

// case KEY_DOWN:
//       while(by <= 0){        
// plateau.clear();
// plateau.print(x,y,p,col);
// plateau.print(bx,++by,balle,colb); 
// usleep(100000);

// // sleep(1);
// } 

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
