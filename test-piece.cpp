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
#include <fstream>


using namespace std ;

void myprogram(){
  int ch;

  int h=20,w=70;

  Window menu(15,26,75,10);
  //nb ligne, longueur,x,y
  Window plateau(h,w,1,6);

  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);

  menu.print(1,1,"Tapez q pour quitter !!!",WBLUE);
  menu.print(2,2,"TIMER : ",WBLUE);

  // string p="XXXXXXXXXXXXXXXXXXXXXXXXX";
  // int x=w/2-(p.size()/2),y=h-1;
  //
  //
  // char balle ='@';
   // int bx = w/2, by =h-2;
  int m=3; //nombre de vie(balle)
int ballx=40, bally=12; //coord départ de la balle
int paddlex=35, paddley=26, paddle; //coord placement paddle départ
int briquex=5, briquey=10, brique;
int miss=0, block=0;
int score[11];
bool xMinus = false;
bool yMinus = false;
bool pad = false;

  char name[3];
string names[11];
ifstream fin;
ofstream fout;




init_paddle(paddle,paddley,paddlex);
init_briques(brique,briquey,briquex);



  Color col=WBLUE;

  Color colb = WRED;
  // plateau.print(x,y,p,col);
  // plateau.print(bx,by,balle,colb);
   while((ch = getch()) != 'q')
 // while((ch = getch()) != 'q' && m!=0)
     {
    switch (ch) {
      case ' ':

      startProgramX();
      break;
      case KEY_LEFT:
          if (paddlex == 2) {
              break;
          }
          else {
              mvaddch(paddley, paddlex+5, ' ');
              paddlex--;
              mvaddch(paddley, paddlex, 'X');
              break;
          }


          case KEY_RIGHT:
  		        if (paddlex+5 == 71) {
  		            break;
  		        }
  		        else {
  		            mvaddch(paddley, paddlex, ' ');
  		            paddlex++;
  		            mvaddch(paddley, paddlex+5, 'X');
  		            break;
  		        }




//       case '1':
//   col=BMAGENTA;
//   break;
//       case '2':
//   col=WCYAN;
//   break;
//       case 'c':
//   plateau.clear();
//   break;
//  //      case KEY_UP:
//   // plateau.print(x,y,' ');
//   // plateau.print(x,--y,p,col);
//   // break;
//  //      case KEY_DOWN:
//   // plateau.print(x,y,' ');
//   // plateau.print(x,++y,p,col);
//   // break;
//       case KEY_LEFT:
//       // if(x>0){
//       //  plateau.clear();
//
// // plateau.print(bx,by,balle,colb);
// //   plateau.print(x,y,' ');
// //   plateau.print(--x,y,p,col); }
//   break;
//       case KEY_RIGHT:
// //   if(x+p.size() < w){
// //        plateau.clear();
// // plateau.print(bx,by,balle,colb);
// //   plateau.print(x,y,' ');
//
//   // plateau.print(++x,y,p,col); }
//   break;
//
//   case ' ':
// //       while(by > 0){
// // plateau.clear();
// // plateau.print(x,y,p,col);
// // plateau.print(bx,--by,balle,colb);
// // usleep(100000);
//
// // sleep(1);
// }
//
// // while (by < h-2){
// // plateau.clear();
// // plateau.print(x,y,p,col);
// // plateau.print(bx,++by,balle,colb);
// // usleep(100000); }
//
// // case KEY_DOWN:
// //       while(by <= 0){
// // plateau.clear();
// // plateau.print(x,y,p,col);
// // plateau.print(bx,++by,balle,colb);
// // usleep(100000);
//
// // // sleep(1);
// // }
//
//   break;
//       case '\n':
//   // x=w/2,y=h/2;
//   // plateau.print(x,y,p,col);
//   break;
//
//
//
  case '\t':

   Color tmp= menu.getCouleurBordure();
   menu.setCouleurBordure(plateau.getCouleurBordure());
   plateau.setCouleurBordure(tmp);
   init_paddle(paddle,paddley,paddlex);
   init_briques(brique,briquey,briquex);
 break;
    }

    mvaddch(bally,ballx,' ');

        if (ballx == 2 && bally == 7) { //la balle touche le coin supérieur gauche
            moveBally(bally, yMinus);
            moveBallx(ballx, xMinus);
        }
        else
            if (bally == 26 && ballx == 2) { //la balle touche le coin inférieur gauche
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
		else
            if (ballx == 70 || ballx == 2) { //la balle touche le côté gauche ou droit
			moveBallx(ballx, xMinus);
		}
        else if (bally == 26) { //la balle touche le bas
            if (ballx >= paddlex && ballx <= (paddlex+5)) { //la balle touche le paddle
                moveBallx(ballx, xMinus);
                moveBally(bally, yMinus);
                //block++; //score quand il touche le paddle
            }
            else{ //la balle ne touche pas le paddle
                moveBallx(ballx, xMinus);
                moveBally(bally, yMinus);
                m--; //le nombre de balle(vie) diminue
            }
        }
		else if (bally == 7) { //la balle touche le haut
			moveBally(bally, yMinus);
		}
        else if(ballx == 70 && bally == 7) { //la balle touche le coin supérieur droit
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
        else if(ballx == 70 && bally == 26) { //la balle touche le coin inférieur droit
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
        else if (ballx >= briquex && ballx <= (briquex+5)) { //la balle touche la brique
				moveBallx(ballx, xMinus);
	            moveBally(bally, yMinus);
		}




		if (xMinus && !yMinus) {
			ballx--;
			bally++;
		}
		else if (yMinus && !xMinus) {
			ballx++;
			bally--;
		}
		else if (xMinus && yMinus) {
			ballx--;
			bally--;
		}
		else {
			ballx++;
			bally++;
		}
		//mvaddstr(2, 21, "Blocks: ");
//		mvaddint
		mvaddch(bally,ballx,'@');

	}

   }


int main(int argc, char **argv){

if(argv[1] != NULL){
  printf("PARAMETRE : %s  \n",argv[1] );
}
int choix ; string ligne ;
printf("Taper sur : 1 pour commencer, 2 pour l'aide, 3 pour la version, 4 pour les auteurs.\n" );
cin >>choix ;
// printf("CHOIX : %d\n",choix );

switch(choix){
  case 1 : {
printf("Début partie \n" );
  sleep(2);
  startProgramX();

  myprogram();
  stopProgramX();
}
  break;

  case 2 : {
  printf("Ouverture du ficher help.txt \n");
  sleep(2);
  ifstream fichier1("help.txt", ios::in);  // on ouvre en lecture
  if(fichier1){

          while(getline(fichier1, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
          {
                  cout << ligne << endl;  // on l'affiche
          }
          fichier1.close();
  }
       else{
             cerr << "Impossible d'ouvrir le fichier !" << endl;}
           }
  break;


  case 3 : {
    printf("Ouverture du fichier version.txt \n");
    sleep(2);
    ifstream fichier2("version.txt", ios::in);  // on ouvre en lecture
    if(fichier2){

            while(getline(fichier2, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
            {
                    cout << ligne << endl;  // on l'affiche
            }
            fichier2.close();
    }
         else{
               cerr << "Impossible d'ouvrir le fichier !" << endl;}
             }
  break;
  case 4 : {
    printf("Ouverture du fichier auteur.txt \n");
    sleep(2);
    ifstream fichier3("auteur.txt", ios::in);  // on ouvre en lecture
    if(fichier3){

            while(getline(fichier3, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
            {
                    cout << ligne << endl;  // on l'affiche
            }
            fichier3.close();
    }
         else{
               cerr << "Impossible d'ouvrir le fichier !" << endl;}
             }
  break;


}
if(choix > 4){
  printf("Le choix numéro : %d n'existe pas.\n", choix);
}

  return 0;
}
