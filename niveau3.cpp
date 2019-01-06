#include "niveau3.h"
#include "window.h"
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
#define PADDLE_LENGTH 7
#define BLOCK_LENGTH 10
#define SPACE 5
#define NBVIE 2



struct Block{
	int x;
	int y;
};


void startNIVEAU3(){
	printf("Début partie (%i vies) \n", NBVIE);
  sleep(1);


int vie=NBVIE; //nombre de vie(balle)
int paddlex=10, paddley=23, paddle;
int ballx=paddlex+PADDLE_LENGTH/2, bally=SCREEN_HEIGHT-2;
Block A, B, C, D, E, F, G, H, I;
int brique;
A.x=D.x=5;
B.x=E.x=20;
C.x=F.x=35;
A.y=B.y=C.y=7;
D.y=E.y=F.y=12;
G.x = 9;
G.y = 5;

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
int touchG=0;
int nbBriques=7;
ifstream fin;
ofstream fout;
// cout<<"enter your name"<<endl;
// cin>>name;

init_curses();
for (paddle = 0; paddle < PADDLE_LENGTH+1; paddle++) {
	mvaddch(paddley, paddlex+paddle, ' ');
	mvchgat(paddley, paddlex, 7, ' ', BBLUE, NULL);
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

if(touchG==0){
  for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
    mvaddch(G.y, G.x+brique, ' ');
    mvchgat(G.y, G.x, 11, ' ', BRED, NULL);
  }
}
else if(touchG==1){
  for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
    mvaddch(G.y, G.x+brique, ' ');
    mvchgat(G.y, G.x, 11, ' ', BGREEN, NULL);
  }
}
else if(touchG){
  for (brique = 0; brique < BLOCK_LENGTH+1; brique++) {
    mvaddch(G.y, G.x+brique, ' ');
  }
    G.x=0;
    G.y=0;
    if(touchG==2){nbBriques--; touchG++; score+=5;}
}


start_color();
//
WINDOW *win;

    mvaddstr(1,SCREEN_WIDTH+3,"Tapez q pour quitter!");
    mvprintw(2,SCREEN_WIDTH+3,"Score :  %d \n",score);
    mvprintw(3,SCREEN_WIDTH+3,"Vie(s) :  %d \n",vie);
    mvvline(0,SCREEN_WIDTH+1, ACS_VLINE,SCREEN_WIDTH);

    switch(ch) {
    case KEY_LEFT:
		if (paddlex == 0) {
				break;
		}
		else {
				mvaddch(paddley, paddlex+PADDLE_LENGTH, ' ');
				paddlex--;
				mvaddch(paddley, paddlex+PADDLE_LENGTH, ' ');
				mvchgat(paddley, paddlex, 7, ' ', BBLUE, NULL);
				break;
		}
case KEY_RIGHT:
		if (paddlex+PADDLE_LENGTH == SCREEN_WIDTH) {
				break;
		}
		else {
				mvaddch(paddley, paddlex, ' ');
				paddlex++;
				mvaddch(paddley, paddlex+PADDLE_LENGTH, ' ');
				mvchgat(paddley, paddlex, 7, ' ', BBLUE, NULL);
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
printf("Score : %i \n", score);
ofstream myfile;
myfile.open ("score.txt",std::fstream::out | std::fstream::app);
myfile << score;
myfile <<  "\n " ;
myfile.close();


}
