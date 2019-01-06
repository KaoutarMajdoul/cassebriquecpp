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
#include "niveau1.h"
#include "niveau2.h"
#include "niveau3.h"
#include "window.h"
#include "initball.h"

using namespace std;

#define SCREEN_HEIGHT 23
#define SCREEN_WIDTH 50
#define PADDLE_LENGTH 15
#define BLOCK_LENGTH 10
#define SPACE 5
#define NBVIE 7




struct Block{
	int x;
	int y;
};


int main(int argc, char **argv) {

    if(argv[1] != NULL){
  printf("PARAMETRE : %s  \n",argv[1] );
}


int choix ; string ligne ; int niveau ; string pseudo ;
printf("Choisissez un pseudo : \n");
cin>>pseudo;




printf("Taper sur :\n 1 pour commencer le jeu,\n 2 pour l'aide, \n 3 pour la version, \n 4 pour les auteurs, \n 5 pour les premiers scores.\n" );
cin >>choix ;



switch(choix){
  case 1 : {
		printf("Choisir le niveau : 1 (easy)- 2 (medium) - 3 (hard) \n");
		cin >> niveau ;


		
		if (niveau == 1 ){
		printf("Lancement du niveau : %d\n", niveau);


  sleep(1);

startNIVEAU1();
}
if(niveau == 2){


printf("Lancement du niveau : %d\n", niveau);

sleep(1);


startNIVEAU2();



}

if(niveau == 3){
	printf("Lancement du niveau : %d\n", niveau);
sleep(1);
startNIVEAU3();


}
if (niveau > 3 ){

	printf("Le niveau : %d n'existe pas ! \n", niveau);

}

}
break;










//////////////////////////////////////////////////////////////












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
    printf("Ouverture du fichier score.txt \n");
    sleep(2);
    ifstream fichier4("score.txt", ios::in);  // on ouvre en lecture
    if(fichier4){
			int cmpt = 0 ;

            while(getline(fichier4, ligne)&& cmpt <11)  // tant que l'on peut mettre la ligne dans "contenu"
            {//<11 pour pouvoir afficher 5 ligne en coptant les sauts de lignes
                    cout << ligne << endl;  // on l'affiche

										cmpt ++;


            }
            fichier4.close();
    }
         else{
               cerr << "Impossible d'ouvrir le fichier !" << endl;}
             }
  break;




}
if(choix > 5){
  printf("Le choix numéro : %d n'existe pas.\n", choix);
}
	return 0;

}
