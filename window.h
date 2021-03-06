#ifndef __WINDOW_H
#define __WINDOW_H

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

// Ensemble de couleurs possibles (fond+texte)
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
  void init_colors(void);




class Window {
 private:
  int height,width,startx,starty;
  WINDOW* win, *frame;
  Color colorwin, colorframe;
  char bord;
  void update() const;

 public:

  Window(int h,int w, int x, int y, char c='+');

  ~Window();


  void print(int x, int y, std::string s) const;
  void print(int x, int y, char s) const;
  void init_colors(void);

  // accesseurs
  int getX() const;        // récupère l'abscisse du coin supérieur gauche de la fenêtre
  int getY() const;        // récupère l'ordonnée du coin supérieur gauche de la fenêtre
  int getHauteur() const ; // récupère la hauteur de la fenêtre
  int getLargeur() const ; // récupère la largeur de la fenêtre


  Color getCouleurBordure() const; // récupère la couleur de la bordure
  Color getCouleurFenetre() const; // récupère la couleur de la fenêtre
  void setCouleurBordure(Color);   // modifie la couleur de la bordure
  void setCouleurFenetre(Color);   // modifie la couleur de la fenêtre (ATTENTION, tout le contenu de la fenêtre prend la couleur)

  void clear() const; // enleve tout le contenu de la fenêtre

};




#endif
