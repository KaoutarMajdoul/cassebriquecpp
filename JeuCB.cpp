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
// #include <fstream>
// #include "window.h"
using namespace std;

#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 50
#define PADDLE_LENGTH 15
#define BLOCK_LENGTH 10
#define SPACE 5
#define NBVIE 7

void init_curses();
void finish_curses();
void moveBallx(int x, bool &minus);
void moveBally(int y, bool &minus);

enum Color {
  WBLACK,  // couleur fond = noir ,   couleur texte = blanc
  WCYAN,   // couleur fond = cyan,    couleur texte = blanc
  WBLUE,   // couleur fond = bleu,    couleur texte = blanc
  WYELLOW, // couleur fond = jaune,   couleur texte = blanc
  WGREEN,  // couleur fond = vert,    couleur texte = blanc
  WMAGENTA,// couleur fond = magenta, couleur texte = blanc
  WRED,	   // couleur fond = rouge,   couleur texte = blanc
  BWHITE,  // couleur fond = blanc,   couleur texte = blanc
  BCYAN,   // couleur fond = cyan,    couleur texte = noir
  BBLUE,   // couleur fond = bleu,    couleur texte = noir
  BYELLOW, // couleur fond = jaune,   couleur texte = noir
  BGREEN,  // couleur fond = vert,    couleur texte = noir
  BMAGENTA,// couleur fond = magenta, couleur texte = noir
  BRED,    // couleur fond = rouge,   couleur texte = noir
};


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


struct Block{
	int x;
	int y;
};





int main(int argc, char **argv) {

    if(argv[1] != NULL){
  printf("PARAMETRE : %s  \n",argv[1] );
}
int choix ; string ligne ;
printf("Taper sur : 1 pour commencer, 2 pour l'aide, 3 pour la version, 4 pour les auteurs, 5 pour les meilleures scores\n" );
cin >>choix ;
// printf("CHOIX : %d\n",choix );

switch(choix){
  case 1 : {
printf("Début partie (%i vies) \n", NBVIE );
  sleep(2);


  int vie=NBVIE; //nombre de vie(balle)
	int paddlex=4, paddley=23, paddle;
	int ballx=paddlex+PADDLE_LENGTH/2, bally=SCREEN_HEIGHT-2;
	Block A, B, C, D, E, F;
	int brique;
	A.x=D.x=5;
	B.x=E.x=20;
	C.x=F.x=35;
	A.y=B.y=C.y=7;
	D.y=E.y=F.y=12;

	int score=0;
	bool xMinus = false;
	bool yMinus = false;
	int ch;
	int touchA=0;
	int touchB=0;
	int touchC=0;
	int touchD=0;
	int touchE=0;
	int touchF=0;
	int nbBriques=6;
	ifstream fin;
	ofstream fout;
	// cout<<"enter your name"<<endl;
 	// cin>>name;

	init_curses();
	for (paddle = 0; paddle < PADDLE_LENGTH+1; paddle++) {
		mvaddch(paddley, paddlex+paddle, 'X');
	}
		printf("Score: %i \n", score);
	while ((ch = getch()) != 'q' && vie!=0 && nbBriques!=0) {

		if(touchA==0){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(A.y, A.x+brique, ' ');
				mvchgat(A.y, A.x, 11, ' ', WRED, NULL);
			}
		}
		else if(touchA==1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(A.y, A.x+brique, ' ');
				mvchgat(A.y, A.x, 11, ' ', BGREEN, NULL);
			}
		}
		else if(touchA>1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(A.y, A.x+brique, ' ');
			}
				A.x=0;
				A.y=0;
				if(touchA==2){nbBriques--; touchA++; score+=5;}
		}


		if(touchB==0){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(B.y, B.x+brique, ' ');
					mvchgat(B.y, B.x, 11, ' ', WRED, NULL);
			}
		}
		else if(touchB==1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(B.y, B.x+brique, ' ');
					mvchgat(B.y, B.x, 11, ' ', BGREEN, NULL);
			}
		}
		else if(touchB>1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(B.y, B.x+brique, ' ');
			}
				B.x=0;
				B.y=0;
				if(touchB==2){nbBriques--; touchB++; score+=5;}
		}


		if(touchC==0){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(C.y, C.x+brique, ' ');
						mvchgat(C.y, C.x, 11, ' ', BRED, NULL);
			}
		}
		else if(touchC==1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(C.y, C.x+brique, ' ');
				mvchgat(C.y, C.x, 11, ' ', BGREEN, NULL);
			}
		}
		else if(touchC>1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(C.y, C.x+brique, ' ');
			}
				C.x=0;
				C.y=0;
				if(touchC==2){nbBriques--; touchC++; score+=5;}
		}
		if(touchD==0){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(D.y, D.x+brique, ' ');
				mvchgat(D.y, D.x, 11, ' ', BRED, NULL);
			}
		}
		else if(touchD==1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(D.y, D.x+brique, ' ');
				mvchgat(D.y, D.x, 11, ' ', BGREEN, NULL);
			}
		}
		else if(touchD>1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(D.y, D.x+brique, ' ');
			}
				D.x=0;
				D.y=0;
				if(touchD==2){nbBriques--; touchD++; score+=5;}
		}


		if(touchE==0){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(E.y, E.x+brique, ' ');
				mvchgat(E.y, E.x, 11, ' ', BRED, NULL);
			}
		}
		else if(touchE==1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(E.y, E.x+brique, ' ');
				mvchgat(E.y, E.x, 11, ' ', BGREEN, NULL);
			}
		}
		else if(touchE>1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(E.y, E.x+brique, ' ');
			}
				E.x=0;
				E.y=0;
				if(touchE==2){nbBriques--; touchE++; score+=5;}
		}


		if(touchF==0){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(F.y, F.x+brique, ' ');
				mvchgat(F.y, F.x, 11, ' ', BRED, NULL);
			}
		}
		else if(touchF==1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(F.y, F.x+brique, ' ');
				mvchgat(F.y, F.x, 11, ' ', BGREEN, NULL);
			}
		}
		else if(touchF>1){
			for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
				mvaddch(F.y, F.x+brique, ' ');
			}
				F.x=0;
				F.y=0;
				if(touchF==2){nbBriques--; touchF++; score+=5;}
		}
start_color();
	//
	 WINDOW *win;

        mvaddstr(1,53,"Tapez q pour quitter!");
	  ifstream is ;
	  ofstream os ;
	  is . open ( "5meilleures.txt" ) ;
	  os . open ( "5meilleures.txt" , ios :: out| ios :: app ) ;
	  os << "Joueur=" << score << endl ; // remplacer joueur par la variable string nomjoueur
	  os . close () ;
	  is . close () ;
	  
	
	
				mvprintw(2,53,"Score :  %d \n",score);
				mvprintw(3,53,"Vie(s) :  %d \n",vie);
mvvline(0,51, ACS_VLINE,50);

        switch(ch) {
    		case KEY_LEFT:
		       	if (paddlex == 0) {
		            break;
		        }
		        else {
		            mvaddch(paddley, paddlex+PADDLE_LENGTH, ' ');
		            paddlex--;
		            mvaddch(paddley, paddlex, 'X');
		            break;
		        }
	    	case KEY_RIGHT:
		        if (paddlex+PADDLE_LENGTH == SCREEN_WIDTH) {
		            break;
		        }
		        else {
		            mvaddch(paddley, paddlex, ' ');
		            paddlex++;
		            mvaddch(paddley, paddlex+PADDLE_LENGTH, 'X');
		            break;
		        }
    	}


		mvaddch(bally,ballx,' ');

        if (ballx == 0 && bally == 0) { //la balle touche le coin supérieur gauche
            moveBally(bally, yMinus);
            moveBallx(ballx, xMinus);
        }
        else
            if (bally == SCREEN_HEIGHT-1 && ballx == 0) { //la balle touche le coin inférieur gauche
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
		else
            if (ballx == SCREEN_WIDTH || ballx == 0) { //la balle touche le côté gauche ou droit
			moveBallx(ballx, xMinus);
		}
        else if (bally == SCREEN_HEIGHT-1) { //la balle touche le bas
            if (ballx >= paddlex && ballx <= (paddlex+PADDLE_LENGTH)) { //la balle touche le paddle
                moveBallx(ballx, xMinus);
                moveBally(bally, yMinus);

            }
            else{ //la balle ne touche pas le paddle
                moveBallx(ballx, xMinus);
                moveBally(bally, yMinus);
                vie--; //le nombre de balle(vie) diminue
            }
        }
		else if (bally == 0) { //la balle touche le haut
			moveBally(bally, yMinus);
		}
        else if(ballx == SCREEN_WIDTH && bally == 0) { //la balle touche le coin supérieur droit
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
        else if(ballx == SCREEN_WIDTH && bally == SCREEN_HEIGHT-1) { //la balle touche le coin inférieur droit
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
        else if((bally==A.y+1 && ballx>=A.x && ballx<=A.x+BLOCK_LENGTH) || (bally==A.y && ballx==A.x+BLOCK_LENGTH+1)) { //la balle touche la brique en bas ou à droite
			xMinus=false;
			yMinus=false;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchA++;
		}
		else if((bally==A.y-1 && ballx>=A.x && ballx<=A.x+BLOCK_LENGTH) || (bally==A.y && ballx==A.x-1)){ //la balle touche la brique en haut ou à gauche
			xMinus=true;
			yMinus=true;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchA++;
		}
		else if((bally==B.y+1 && ballx>=B.x && ballx<=B.x+BLOCK_LENGTH) || (bally==B.y && ballx==B.x+BLOCK_LENGTH+1)) { //la balle touche la brique en bas ou à droite
			xMinus=false;
			yMinus=false;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchB++;
		}
		else if((bally==B.y-1 && ballx>=B.x && ballx<=B.x+BLOCK_LENGTH) || (bally==B.y && ballx==B.x-1)){ //la balle touche la brique en haut ou à gauche
			xMinus=true;
			yMinus=true;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchB++;
		}
		else if((bally==C.y+1 && ballx>=C.x && ballx<=C.x+BLOCK_LENGTH) || (bally==C.y && ballx==C.x+BLOCK_LENGTH+1)) { //la balle touche la brique en bas ou à droite
			xMinus=false;
			yMinus=false;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchC++;
		}
		else if((bally==C.y-1 && ballx>=C.x && ballx<=C.x+BLOCK_LENGTH) || (bally==C.y && ballx==C.x-1)){ //la balle touche la brique en haut ou à gauche
			xMinus=true;
			yMinus=true;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchC++;
		}
		else if((bally==D.y+1 && ballx>=D.x && ballx<=D.x+BLOCK_LENGTH) || (bally==D.y && ballx==D.x+BLOCK_LENGTH+1)) { //la balle touche la brique en bas ou à droite
			xMinus=false;
			yMinus=false;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchD++;
		}
		else if((bally==D.y-1 && ballx>=D.x && ballx<=D.x+BLOCK_LENGTH) || (bally==D.y && ballx==D.x-1)){ //la balle touche la brique en haut ou à gauche
			xMinus=true;
			yMinus=true;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchD++;
		}
		else if((bally==E.y+1 && ballx>=E.x-1 && ballx<=E.x+BLOCK_LENGTH) || (bally==E.y && ballx==E.x+BLOCK_LENGTH+1)) { //la balle touche la brique en bas ou à droite
			xMinus=false;
			yMinus=false;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchE++;
		}
		else if((bally==E.y-1 && ballx>=E.x-1 && ballx<=E.x+BLOCK_LENGTH) || (bally==E.y && ballx==E.x-1)){ //la balle touche la brique en haut ou à gauche
			xMinus=true;
			yMinus=true;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchE++;
		}
		else if((bally==F.y+1 && ballx>=F.x && ballx<=F.x+BLOCK_LENGTH) || (bally==F.y && ballx==F.x+BLOCK_LENGTH+1)) { //la balle touche la brique en bas ou à droite
			xMinus=false;
			yMinus=false;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchF++;
		}
		else if((bally==F.y-1 && ballx>=F.x && ballx<=F.x+BLOCK_LENGTH) || (bally==F.y && ballx==F.x-1)){ //la balle touche la brique en haut ou à gauche
			xMinus=true;
			yMinus=true;
            moveBallx(ballx, xMinus);
        	moveBally(bally, yMinus);
        	score++;
        	touchF++;
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
		mvaddch(bally,ballx,'*');
		mvchgat(bally, ballx,1 , ' ', BWHITE, NULL);

	}
	finish_curses();
	printf("Score: %i \n", score);
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
  case 5 : {
	  ifstream is ;
	  is . open ( "5meilleures.txt" ) ;
	  string nom ;
	  string score ;
	  while ( ! is . eof () ) {
		  getline ( is , nom , '=' ) ;
		  is >> score ;
		  cout << nom << "        " << score << endl ;
		  getline ( is , nom ) ;		  
	  }
  }

}
if(choix > 5){
  printf("Le choix numéro : %d n'existe pas.\n", choix);
}
	return 0;

}
void init_curses() {
	// initscr();
  //   keypad(stdscr, TRUE);
  //   nonl();
  //   cbreak();
  //   noecho();
  //   halfdelay(1);
	//
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
