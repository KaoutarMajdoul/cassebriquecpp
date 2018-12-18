#include<iostream>
#include<curses.h>
#include <ncurses.h>
#include<fstream>
#include<cstring>
#include "window.h"
using namespace std;
void init_curses(); 
void finish_curses();
//void movePaddle(int &y, char dir, bool &pad);
void moveBallx(int x, bool &minus);
void moveBally(int y, bool &minus);
void sortScore(int score[], string names[]);
void printScore(int score[], string names[]);
int overallScore(int block, int miss);
int exp(int a, int b);

int main() {
    // int x=(w/2)-(p.size()/2);
    // int y=h-1;
    // plateau.print(x,y,p,col);
    int m=3; //nombre de vie(balle)
	int ballx=40, bally=12;
	int paddlex=4, paddley=23, paddle;
	int briquex=5, briquey=10, brique;
	int miss=0, block=0;
	int score[11];
	bool xMinus = false;
	bool yMinus = false;
	bool pad = false;
	int ch;
    char name[3];
	string names[11];
	ifstream fin;
	ofstream fout;
	// cout<<"enter your name"<<endl;
 //    cin>>name;
	
	init_curses();
	for (paddle = 0; paddle < 6; paddle++) {
		mvaddch(paddley, paddlex+paddle, 'X');
	}
	
	while ((ch = getch()) != 'q' && m!=0) {
		for (brique = 0; brique < 6; brique++) {
			mvaddch(briquey, briquex+brique, 'T');
		}

		//mvaddstr(5,10,"TTTTT");
        mvaddstr(1,1,"Tapez q pour quitter!");
		//movePaddle(paddley, ch, pad);
        switch(ch) {
    		case KEY_LEFT:
		       	if (paddlex == 0) {
		            break;
		        }
		        else {
		            mvaddch(paddley, paddlex+5, ' ');
		            paddlex--;
		            mvaddch(paddley, paddlex, 'X');
		            break;
		        }
	    	case KEY_RIGHT:
		        if (paddlex+5 == 79) {
		            break;
		        }
		        else {
		            mvaddch(paddley, paddlex, ' ');
		            paddlex++;
		            mvaddch(paddley, paddlex+5, 'X');
		            break;
		        }
    	}
		
		
		mvaddch(bally,ballx,' ');
		
        if (ballx == 0 && bally == 0) { //la balle touche le coin supérieur gauche
            moveBally(bally, yMinus);
            moveBallx(ballx, xMinus);
        }
        else 
            if (bally == 22 && ballx == 0) { //la balle touche le coin inférieur gauche
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }       
		else 
            if (ballx == 79 || ballx == 0) { //la balle touche le côté gauche ou droit
			moveBallx(ballx, xMinus);
		}
        else if (bally == 22) { //la balle touche le bas
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
		else if (bally == 0) { //la balle touche le haut
			moveBally(bally, yMinus);
		}
        else if(ballx == 79 && bally == 0) { //la balle touche le coin supérieur droit
            moveBallx(ballx, xMinus);
            moveBally(bally, yMinus);
        }
        else if(ballx == 79 && bally == 22) { //la balle touche le coin inférieur droit
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
	finish_curses();    	
	return 0;
	
}
void init_curses() {
	initscr();     
    keypad(stdscr, TRUE);  
    nonl();         
    cbreak();       
    noecho(); 
    halfdelay(1);
}
void finish_curses() {
	endwin();
    system("clear");
    cout << "All Done!" << endl;
}

void moveBallx(int x, bool &minus) {
	if (x == 0) {
		minus = false;
		//miss++;
	}
	// else if (x == 5) {
	// 	minus = false;
	// }
	else if (x == 79) {
		minus = true;
	}
}
void moveBally(int y, bool &minus) {
	if (y == 0) {
		minus = false;
	}
	else if (y == 22) {
		minus = true;
	}	
}


//void movePaddle(int &x, char ch, bool &pad) {
 //    switch(ch) {
    // // case 'W':
    // case KEY_LEFT:
    //  if (x == 0) {
    //      break;
    //  }
    //  else {
    //      mvaddch(10, x+4, ' ');
    //      x--;
    //      mvaddch(10, x, '.');
    //      break;
    //  }
    // // case 'S':
    // case KEY_RIGHT:
    //  if (x+4 == 79) {
    //      break;
    //  }
    //  else {
    //      mvaddch(10, x, ' ');
    //      x++;
    //      mvaddch(10, x+4, '.');
    //      break;
    //  }
    // }
//}
